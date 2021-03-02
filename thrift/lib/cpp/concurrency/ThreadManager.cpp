/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp/concurrency/ThreadManager.h>

#include <atomic>
#include <cassert>
#include <chrono>
#include <memory>
#include <queue>
#include <set>
#include <string>

#include <glog/logging.h>

#include <folly/Conv.h>
#include <folly/CppAttributes.h>
#include <folly/DefaultKeepAliveExecutor.h>
#include <folly/ExceptionString.h>
#include <folly/GLog.h>
#include <folly/ThreadLocal.h>
#include <folly/VirtualExecutor.h>
#include <folly/concurrency/PriorityUnboundedQueueSet.h>
#include <folly/concurrency/QueueObserver.h>
#include <folly/executors/Codel.h>
#include <folly/executors/MeteredExecutor.h>
#include <folly/io/async/Request.h>
#include <folly/portability/GFlags.h>
#include <folly/synchronization/LifoSem.h>
#include <folly/synchronization/SmallLocks.h>
#include <folly/tracing/StaticTracepoint.h>

DEFINE_bool(codel_enabled, false, "Enable codel queue timeout algorithm");

namespace apache {
namespace thrift {
namespace concurrency {

namespace {
/* Translates from wangle priorities (normal at 0, higher is higher)
   to thrift priorities */
PRIORITY translatePriority(int8_t priority) {
  if (priority >= 3) {
    return PRIORITY::HIGH_IMPORTANT;
  } else if (priority == 2) {
    return PRIORITY::HIGH;
  } else if (priority == 1) {
    return PRIORITY::IMPORTANT;
  } else if (priority == 0) {
    return PRIORITY::NORMAL;
  } else if (priority <= -1) {
    return PRIORITY::BEST_EFFORT;
  }
  folly::assume_unreachable();
}

constexpr size_t NORMAL_PRIORITY_MINIMUM_THREADS = 1;

template <typename ExecutorT>
class ExecutorWithSourceAndPriority : public folly::Executor {
 public:
  using Source = ThreadManager::Source;
  static std::unique_ptr<folly::Executor>
  create(PRIORITY priority, Source source, ExecutorT* executor) {
    auto x = new ExecutorWithSourceAndPriority<ExecutorT>(
        priority, source, executor);
    return std::unique_ptr<folly::Executor>(x);
  }

  void add(folly::Func f) override {
    executor_->addWithPriorityAndSource(std::move(f), priority_, source_);
  }

  bool keepAliveAcquire() noexcept override {
    return Executor::keepAliveAcquire(executor_);
  }

  void keepAliveRelease() noexcept override {
    Executor::keepAliveRelease(executor_);
  }

 private:
  ExecutorWithSourceAndPriority(
      PRIORITY priority,
      Source source,
      ExecutorT* executor)
      : priority_(priority), source_(source), executor_(executor) {}

  PRIORITY priority_;
  Source source_;
  ExecutorT* executor_;
};

class Deleter {
 public:
  void operator()(folly::Executor* executor) {
    if (owning_) {
      std::default_delete<folly::Executor>()(executor);
    }
  }
  void unown() {
    owning_ = false;
  }

 private:
  bool owning_{true};
};

template <class F>
void nothrow(const char* name, F&& f) {
  try {
    f();
  } catch (const std::exception& e) {
    LOG(ERROR) << name << " threw unhandled " << folly::exceptionStr(e);
  } catch (...) {
    LOG(ERROR) << name << " threw unhandled "
               << folly::exceptionStr(std::current_exception());
  }
}

} // namespace

/**
 * ThreadManager class
 *
 * This class manages a pool of threads. It uses a ThreadFactory to create
 * threads.  It never actually creates or destroys worker threads, rather
 * it maintains statistics on number of idle threads, number of active threads,
 * task backlog, and average wait and service times.
 *
 * @version $Id:$
 */

class ThreadManager::Task {
 public:
  Task(
      std::shared_ptr<Runnable> runnable,
      const std::chrono::milliseconds& expiration,
      size_t qpriority)
      : runnable_(std::move(runnable)),
        queueBeginTime_(std::chrono::steady_clock::now()),
        expireTime_(
            expiration > std::chrono::milliseconds::zero()
                ? queueBeginTime_ + expiration
                : std::chrono::steady_clock::time_point()),
        context_(folly::RequestContext::saveContext()),
        qpriority_(qpriority) {}

  ~Task() {}

  void run() {
    folly::RequestContextScopeGuard rctx(context_);
    nothrow("worker task", [&] { runnable_->run(); });
    nothrow("worker dtor", [&] { runnable_.reset(); });
  }

  void skip() {
    folly::RequestContextScopeGuard rctx(context_);
    nothrow("worker dtor", [&] { runnable_.reset(); });
  }

  const std::shared_ptr<Runnable>& getRunnable() const {
    return runnable_;
  }

  std::chrono::steady_clock::time_point getExpireTime() const {
    return expireTime_;
  }

  std::chrono::steady_clock::time_point getQueueBeginTime() const {
    return queueBeginTime_;
  }

  bool canExpire() const {
    return expireTime_ != std::chrono::steady_clock::time_point();
  }

  const std::shared_ptr<folly::RequestContext>& getContext() const {
    return context_;
  }

  intptr_t& queueObserverPayload() {
    return queueObserverPayload_;
  }

  size_t queuePriority() const {
    return qpriority_;
  }

 private:
  std::shared_ptr<Runnable> runnable_;
  std::chrono::steady_clock::time_point queueBeginTime_;
  std::chrono::steady_clock::time_point expireTime_;
  std::shared_ptr<folly::RequestContext> context_;
  size_t qpriority_;
  intptr_t queueObserverPayload_;
};

class ThreadManager::Impl : public ThreadManager,
                            public folly::DefaultKeepAliveExecutor {
  class Worker;

 public:
  explicit Impl(bool enableTaskStats = false, size_t numPriorities = 1)
      : workerCount_(0),
        intendedWorkerCount_(0),
        idleCount_(0),
        totalTaskCount_(0),
        expiredCount_(0),
        workersToStop_(0),
        enableTaskStats_(enableTaskStats),
        statsLock_{0},
        waitingTimeUs_(0),
        executingTimeUs_(0),
        numTasks_(0),
        state_(ThreadManager::UNINITIALIZED),
        tasks_(N_SOURCES * numPriorities),
        deadWorkers_(),
        namePrefix_(""),
        namePrefixCounter_(0),
        codelEnabled_(false || FLAGS_codel_enabled) {}

  ~Impl() override {
    stop();
  }

  void start() override;

  void stop() override {
    stopImpl(false);
  }

  void join() override {
    stopImpl(true);
  }

  ThreadManager::STATE state() const override {
    return state_;
  }

  std::shared_ptr<ThreadFactory> threadFactory() const override {
    std::unique_lock<std::mutex> l(mutex_);
    return threadFactory_;
  }

  void threadFactory(std::shared_ptr<ThreadFactory> value) override {
    std::unique_lock<std::mutex> l(mutex_);
    threadFactory_ = value;
  }

  std::string getNamePrefix() const override {
    std::unique_lock<std::mutex> l(mutex_);
    return namePrefix_;
  }

  void setNamePrefix(const std::string& name) override {
    std::unique_lock<std::mutex> l(mutex_);
    namePrefix_ = name;
  }

  void addWorker(size_t value) override;

  void removeWorker(size_t value) override;

  size_t idleWorkerCount() const override {
    return idleCount_;
  }

  size_t workerCount() const override {
    return workerCount_;
  }

  size_t pendingTaskCount() const override {
    return tasks_.size();
  }

  size_t pendingUpstreamTaskCount() const override {
    size_t count = 0;
    for (size_t i = 1; i < tasks_.priorities(); i += 3) {
      count += tasks_.at_priority(i).size();
      count += tasks_.at_priority(i + 1).size();
    }
    return count;
  }

  size_t totalTaskCount() const override {
    return totalTaskCount_;
  }

  size_t expiredTaskCount() override {
    std::unique_lock<std::mutex> l(mutex_);
    size_t result = expiredCount_;
    expiredCount_ = 0;
    return result;
  }

  bool canSleep();

  void add(
      std::shared_ptr<Runnable> value,
      int64_t timeout,
      int64_t expiration,
      apache::thrift::concurrency::ThreadManager::Source source) noexcept
      override;
  using ThreadManager::add;

  /**
   * Implements folly::Executor::add()
   */
  void add(folly::Func f) override {
    add(FunctionRunner::create(std::move(f)));
  }

  void remove(std::shared_ptr<Runnable> task) override;

  std::shared_ptr<Runnable> removeNextPending() override;

  void clearPending() override;

  void setExpireCallback(ExpireCallback expireCallback) override;
  void setCodelCallback(ExpireCallback expireCallback) override;
  void setThreadInitCallback(InitCallback initCallback) override {
    initCallback_ = initCallback;
  }

  void getStats(
      std::chrono::microseconds& waitTime,
      std::chrono::microseconds& runTime,
      int64_t maxItems) override;
  void enableCodel(bool) override;
  folly::Codel* getCodel() override;

  // Methods to be invoked by workers
  void workerStarted(Worker* worker);
  void workerExiting(Worker* worker);
  void reportTaskStats(
      const Task& task,
      const std::chrono::steady_clock::time_point& workBegin,
      const std::chrono::steady_clock::time_point& workEnd);
  std::unique_ptr<Task> waitOnTask();
  void onTaskExpired(const Task& task);

  folly::Codel codel_;

  KeepAlive<> getKeepAlive(ExecutionScope, Source) const override {
    LOG(FATAL)
        << "getKeepAlive() should be implemented in derived/wrapper class";
  }

 protected:
  void add(
      size_t priority,
      std::shared_ptr<Runnable> value,
      int64_t timeout,
      int64_t expiration,
      apache::thrift::concurrency::ThreadManager::Source source) noexcept;

  // returns a string to attach to namePrefix when recording
  // stats
  virtual std::string statContext(PRIORITY = PRIORITY::NORMAL) {
    return "";
  }

 private:
  void stopImpl(bool joinArg);
  void removeWorkerImpl(
      std::unique_lock<std::mutex>& lock,
      size_t value,
      bool afterTasks = false);
  bool shouldStop();
  void setupQueueObservers();

  size_t workerCount_;
  // intendedWorkerCount_ tracks the number of worker threads that we currently
  // want to have.  This may be different from workerCount_ while we are
  // attempting to remove workers:  While we are waiting for the workers to
  // exit, intendedWorkerCount_ will be smaller than workerCount_.
  size_t intendedWorkerCount_;
  std::atomic<size_t> idleCount_;
  std::atomic<size_t> totalTaskCount_;
  size_t expiredCount_;
  std::atomic<int> workersToStop_;

  const bool enableTaskStats_;
  folly::MicroSpinLock statsLock_;
  std::chrono::microseconds waitingTimeUs_;
  std::chrono::microseconds executingTimeUs_;
  int64_t numTasks_;

  ExpireCallback expireCallback_;
  ExpireCallback codelCallback_;
  InitCallback initCallback_;

  ThreadManager::STATE state_;
  std::shared_ptr<ThreadFactory> threadFactory_;

  folly::PriorityUMPMCQueueSet<std::unique_ptr<Task>, /* MayBlock = */ false>
      tasks_;

  mutable std::mutex mutex_;
  std::mutex stateUpdateMutex_;
  // cond_ is signaled on any of the following events:
  // - a new task is added to the task queue
  // - state_ changes
  std::condition_variable cond_;
  folly::LifoSem waitSem_;
  // deadWorkerCond_ is signaled whenever a worker thread exits
  std::condition_variable deadWorkerCond_;
  std::deque<std::shared_ptr<Thread>> deadWorkers_;

  folly::ThreadLocal<bool> isThreadManagerThread_{
      [] { return new bool(false); }};
  std::string namePrefix_;
  uint32_t namePrefixCounter_;

  bool codelEnabled_;

  folly::Optional<std::vector<std::unique_ptr<folly::QueueObserver>>>
      queueObservers_;
};

namespace {

class SimpleThreadManagerImpl : public ThreadManager::Impl {
 public:
  explicit SimpleThreadManagerImpl(
      size_t workerCount = 4,
      bool enableTaskStats = false)
      : ThreadManager::Impl(enableTaskStats), workerCount_(workerCount) {
    executors_.reserve(N_SOURCES);
    // for INTERNAL source, this is just a straight pass through
    executors_.emplace_back(this).get_deleter().unown();
    for (int j = 1; j < N_SOURCES; j++) {
      auto wrapper = makeExecutor(static_cast<Source>(j));
      executors_.emplace_back(wrapper.release());
    }
  }

  void start() override {
    if (state() == STARTED) {
      return;
    }
    ThreadManager::Impl::start();
    addWorker(workerCount_);
  }

  KeepAlive<> getKeepAlive(ExecutionScope, Source source) const override {
    DCHECK(static_cast<uint8_t>(source) < executors_.size());
    return getKeepAliveToken(*executors_[static_cast<uint8_t>(source)]);
  }

  void addWithPriorityAndSource(folly::Func f, PRIORITY pri, Source source) {
    DCHECK(pri == PRIORITY::NORMAL);
    add(FunctionRunner::create(std::move(f)), 0, 0, source);
  }

 private:
  std::unique_ptr<Executor> makeExecutor(Source source) {
    return ExecutorWithSourceAndPriority<SimpleThreadManagerImpl>::create(
        PRIORITY::NORMAL, source, this);
  }

  const size_t workerCount_;

  std::vector<std::unique_ptr<Executor, Deleter>> executors_;
};

} // namespace

SimpleThreadManager::SimpleThreadManager(
    size_t workerCount,
    bool enableTaskStats)
    : impl_(std::make_unique<SimpleThreadManagerImpl>(
          workerCount,
          enableTaskStats)) {}

SimpleThreadManager::~SimpleThreadManager() {
  joinKeepAliveOnce();
}

void SimpleThreadManager::start() {
  return impl_->start();
}
void SimpleThreadManager::stop() {
  joinKeepAliveOnce();
  return impl_->stop();
}
void SimpleThreadManager::join() {
  joinKeepAliveOnce();
  return impl_->join();
}
ThreadManager::STATE SimpleThreadManager::state() const {
  return impl_->state();
}
std::shared_ptr<ThreadFactory> SimpleThreadManager::threadFactory() const {
  return impl_->threadFactory();
}
void SimpleThreadManager::threadFactory(std::shared_ptr<ThreadFactory> value) {
  return impl_->threadFactory(std::move(value));
}
std::string SimpleThreadManager::getNamePrefix() const {
  return impl_->getNamePrefix();
}
void SimpleThreadManager::setNamePrefix(const std::string& name) {
  return impl_->setNamePrefix(name);
}
void SimpleThreadManager::addWorker(size_t value) {
  return impl_->addWorker(value);
}
void SimpleThreadManager::removeWorker(size_t value) {
  return impl_->removeWorker(value);
}
size_t SimpleThreadManager::idleWorkerCount() const {
  return impl_->idleWorkerCount();
}
size_t SimpleThreadManager::workerCount() const {
  return impl_->workerCount();
}
size_t SimpleThreadManager::pendingTaskCount() const {
  return impl_->pendingTaskCount();
}
size_t SimpleThreadManager::pendingUpstreamTaskCount() const {
  return impl_->pendingUpstreamTaskCount();
}
size_t SimpleThreadManager::totalTaskCount() const {
  return impl_->totalTaskCount();
}
size_t SimpleThreadManager::expiredTaskCount() {
  return impl_->expiredTaskCount();
}
void SimpleThreadManager::add(
    std::shared_ptr<Runnable> task,
    int64_t timeout,
    int64_t expiration,
    Source source) noexcept {
  return impl_->add(std::move(task), timeout, expiration, source);
}
void SimpleThreadManager::add(folly::Func f) {
  return impl_->add(std::move(f));
}
void SimpleThreadManager::remove(std::shared_ptr<Runnable> task) {
  return impl_->remove(std::move(task));
}
std::shared_ptr<Runnable> SimpleThreadManager::removeNextPending() {
  return impl_->removeNextPending();
}
void SimpleThreadManager::clearPending() {
  return impl_->clearPending();
}
void SimpleThreadManager::enableCodel(bool value) {
  return impl_->enableCodel(value);
}
folly::Codel* SimpleThreadManager::getCodel() {
  return impl_->getCodel();
}
void SimpleThreadManager::setExpireCallback(ExpireCallback cb) {
  return impl_->setExpireCallback(std::move(cb));
}
void SimpleThreadManager::setCodelCallback(ExpireCallback cb) {
  return impl_->setCodelCallback(std::move(cb));
}
void SimpleThreadManager::setThreadInitCallback(InitCallback cb) {
  return impl_->setThreadInitCallback(std::move(cb));
}
void SimpleThreadManager::getStats(
    std::chrono::microseconds& waitTime,
    std::chrono::microseconds& runTime,
    int64_t maxItems) {
  return impl_->getStats(waitTime, runTime, maxItems);
}

folly::Executor::KeepAlive<> SimpleThreadManager::getKeepAlive(
    ExecutionScope es,
    Source source) const {
  return impl_->getKeepAlive(std::move(es), source);
}

class ThreadManager::Impl::Worker : public Runnable {
 public:
  Worker(ThreadManager::Impl* manager) : manager_(manager) {}

  ~Worker() override {}

  /**
   * Worker entry point
   *
   * As long as worker thread is running, pull tasks off the task queue and
   * execute.
   */
  void run() override {
    // Inform our manager that we are starting
    manager_->workerStarted(this);

    while (true) {
      // Wait for a task to run
      auto task = manager_->waitOnTask();

      // A nullptr task means that this thread is supposed to exit
      if (!task) {
        manager_->workerExiting(this);
        return;
      }

      if (manager_->queueObservers_) {
        manager_->queueObservers_->at(task->queuePriority())
            ->onDequeued(task->queueObserverPayload());
      }

      auto startTime = std::chrono::steady_clock::now();

      // Codel auto-expire time algorithm
      auto delay = std::chrono::duration_cast<std::chrono::milliseconds>(
          startTime - task->getQueueBeginTime());
      if (task->canExpire() && manager_->codel_.overloaded(delay)) {
        if (manager_->codelCallback_) {
          manager_->codelCallback_(task->getRunnable());
        }
        if (manager_->codelEnabled_) {
          FB_LOG_EVERY_MS(WARNING, 10000) << "Queueing delay timeout";
          manager_->onTaskExpired(*task);
          task->skip();
          continue;
        }
      }

      if (manager_->observer_) {
        // Hold lock to ensure that observer_ does not get deleted
        folly::SharedMutex::ReadHolder g(manager_->observerLock_);
        if (manager_->observer_) {
          manager_->observer_->preRun(task->getContext().get());
        }
      }

      // Check if the task is expired
      if (task->canExpire() && task->getExpireTime() <= startTime) {
        manager_->onTaskExpired(*task);
        task->skip();
        continue;
      }

      task->run();
      auto endTime = std::chrono::steady_clock::now();
      manager_->reportTaskStats(*task, startTime, endTime);
    }
  }

 private:
  ThreadManager::Impl* manager_;
};

void ThreadManager::Impl::addWorker(size_t value) {
  for (size_t ix = 0; ix < value; ix++) {
    auto worker = std::make_shared<Worker>(this);
    auto thread = threadFactory_->newThread(worker, ThreadFactory::ATTACHED);
    {
      // We need to increment idle count
      std::unique_lock<std::mutex> l(mutex_);
      if (state_ != STARTED) {
        throw IllegalStateException(
            "ThreadManager::addWorker(): "
            "ThreadManager not running");
      }
      idleCount_++;
    }

    try {
      thread->start();
    } catch (...) {
      // If thread is started unsuccessfully, we need to decrement the
      // count we incremented above
      std::unique_lock<std::mutex> l(mutex_);
      idleCount_--;
      throw;
    }

    std::unique_lock<std::mutex> l(mutex_);
    workerCount_++;
    intendedWorkerCount_++;
  }
}

void ThreadManager::Impl::workerStarted(Worker* worker) {
  InitCallback initCallback;
  {
    std::unique_lock<std::mutex> l(mutex_);
    assert(idleCount_ > 0);
    --idleCount_;
    ++totalTaskCount_;
    std::shared_ptr<Thread> thread = worker->thread();
    *isThreadManagerThread_ = true;
    initCallback = initCallback_;
    if (!namePrefix_.empty()) {
      thread->setName(
          folly::to<std::string>(namePrefix_, "-", ++namePrefixCounter_));
    }
  }

  if (initCallback) {
    initCallback();
  }
}

void ThreadManager::Impl::workerExiting(Worker* worker) {
  std::unique_lock<std::mutex> l(mutex_);

  std::shared_ptr<Thread> thread = worker->thread();

  --workerCount_;
  --totalTaskCount_;
  deadWorkers_.push_back(thread);
  deadWorkerCond_.notify_one();
}

void ThreadManager::Impl::start() {
  std::unique_lock<std::mutex> sl(stateUpdateMutex_);
  std::unique_lock<std::mutex> l(mutex_);

  if (state_ == ThreadManager::STOPPED) {
    return;
  }

  if (state_ == ThreadManager::UNINITIALIZED) {
    if (threadFactory_ == nullptr) {
      throw InvalidArgumentException();
    }
    state_ = ThreadManager::STARTED;
    setupQueueObservers();
    cond_.notify_all();
  }
}

void ThreadManager::Impl::stopImpl(bool joinArg) {
  std::unique_lock<std::mutex> sl(stateUpdateMutex_);

  if (state_ == ThreadManager::UNINITIALIZED) {
    // The thread manager was never started.  Just ignore the stop() call.
    // This will happen if the ThreadManager is destroyed without ever being
    // started.
    joinKeepAlive();
    std::unique_lock<std::mutex> l(mutex_);
    state_ = ThreadManager::STOPPED;
  } else if (state_ == ThreadManager::STARTED) {
    joinKeepAlive();
    std::unique_lock<std::mutex> l(mutex_);
    if (joinArg) {
      state_ = ThreadManager::JOINING;
      removeWorkerImpl(l, intendedWorkerCount_, true);
      assert(tasks_.empty());
    } else {
      state_ = ThreadManager::STOPPING;
      removeWorkerImpl(l, intendedWorkerCount_);
      // Empty the task queue, in case we stopped without running
      // all of the tasks.
      totalTaskCount_ -= tasks_.size();
      std::unique_ptr<Task> task;
      while (tasks_.try_dequeue(task)) {
      }
    }
    state_ = ThreadManager::STOPPED;
    cond_.notify_all();
  } else {
    std::unique_lock<std::mutex> l(mutex_);
    // Another stopImpl() call is already in progress.
    // Just wait for the state to change to STOPPED
    while (state_ != ThreadManager::STOPPED) {
      cond_.wait(l);
    }
  }

  assert(workerCount_ == 0);
  assert(intendedWorkerCount_ == 0);
  assert(idleCount_ == 0);
  assert(totalTaskCount_ == 0);
}

void ThreadManager::Impl::removeWorker(size_t value) {
  std::unique_lock<std::mutex> l(mutex_);
  removeWorkerImpl(l, value);
}

void ThreadManager::Impl::removeWorkerImpl(
    std::unique_lock<std::mutex>& lock,
    size_t value,
    bool afterTasks) {
  assert(lock.owns_lock());

  if (value > intendedWorkerCount_) {
    throw InvalidArgumentException();
  }
  intendedWorkerCount_ -= value;

  if (afterTasks) {
    // Insert nullptr tasks onto the tasks queue to ask workers to exit
    // after all current tasks are completed
    for (size_t n = 0; n < value; ++n) {
      auto const qpriority = tasks_.priorities() - 1;
      tasks_.at_priority(qpriority).enqueue(nullptr);
      ++totalTaskCount_;
    }
    cond_.notify_all();
    for (size_t n = 0; n < value; ++n) {
      waitSem_.post();
    }
  } else {
    // Ask threads to exit ASAP
    workersToStop_ += value;
    cond_.notify_all();
    for (size_t n = 0; n < value; ++n) {
      waitSem_.post();
    }
  }

  // Wait for the specified number of threads to exit
  for (size_t n = 0; n < value; ++n) {
    while (deadWorkers_.empty()) {
      deadWorkerCond_.wait(lock);
    }

    std::shared_ptr<Thread> thread = deadWorkers_.front();
    deadWorkers_.pop_front();
    thread->join();
  }
}

bool ThreadManager::Impl::canSleep() {
  return !(*isThreadManagerThread_);
}

void ThreadManager::Impl::add(
    std::shared_ptr<Runnable> value,
    int64_t timeout,
    int64_t expiration,
    ThreadManager::Source source) noexcept {
  add(0, std::move(value), timeout, expiration, source);
}

void ThreadManager::Impl::add(
    size_t priority,
    std::shared_ptr<Runnable> value,
    int64_t /*timeout*/,
    int64_t expiration,
    ThreadManager::Source source) noexcept {
  CHECK(
      state_ != ThreadManager::UNINITIALIZED &&
      state_ != ThreadManager::STARTING)
      << "ThreadManager::Impl::add ThreadManager not started";

  if (state_ != ThreadManager::STARTED) {
    LOG(WARNING) << "abort add() that got called after join() or stop()";
    return;
  }

  priority = N_SOURCES * priority + static_cast<int>(source);
  auto const qpriority = std::min(tasks_.priorities() - 1, priority);
  auto task = std::make_unique<Task>(
      std::move(value), std::chrono::milliseconds{expiration}, qpriority);
  if (queueObservers_) {
    task->queueObserverPayload() =
        queueObservers_->at(qpriority)->onEnqueued(task->getContext().get());
  }
  tasks_.at_priority(qpriority).enqueue(std::move(task));

  ++totalTaskCount_;

  if (idleCount_ > 0) {
    // If an idle thread is available notify it, otherwise all worker threads
    // are running and will get around to this task in time.
    waitSem_.post();
  }
}

void ThreadManager::Impl::remove(std::shared_ptr<Runnable> /*task*/) {
  std::unique_lock<std::mutex> l(mutex_);
  if (state_ != ThreadManager::STARTED) {
    throw IllegalStateException(
        "ThreadManager::Impl::remove ThreadManager not "
        "started");
  }

  throw IllegalStateException("ThreadManager::Impl::remove() not implemented");
}

std::shared_ptr<Runnable> ThreadManager::Impl::removeNextPending() {
  std::unique_lock<std::mutex> l(mutex_);
  if (state_ != ThreadManager::STARTED) {
    throw IllegalStateException(
        "ThreadManager::Impl::removeNextPending "
        "ThreadManager not started");
  }

  std::unique_ptr<Task> task;
  if (tasks_.try_dequeue(task)) {
    std::shared_ptr<Runnable> r = task->getRunnable();
    --totalTaskCount_;
    return r;
  } else {
    return std::shared_ptr<Runnable>();
  }
}

void ThreadManager::Impl::clearPending() {
  while (removeNextPending() != nullptr) {
  }
}

bool ThreadManager::Impl::shouldStop() {
  // in normal cases, only do a read (prevents cache line bounces)
  if (workersToStop_ <= 0) {
    return false;
  }
  // modify only if needed
  if (workersToStop_-- > 0) {
    return true;
  } else {
    workersToStop_++;
    return false;
  }
}

std::unique_ptr<ThreadManager::Task> ThreadManager::Impl::waitOnTask() {
  if (shouldStop()) {
    return nullptr;
  }

  std::unique_ptr<Task> task;

  // Fast path - if tasks are ready, get one
  if (tasks_.try_dequeue(task)) {
    --totalTaskCount_;
    return task;
  }

  // Otherwise, no tasks on the horizon, so go sleep
  std::unique_lock<std::mutex> l(mutex_);
  if (shouldStop()) {
    // check again because it might have changed by the time we got the mutex
    return nullptr;
  }

  ++idleCount_;
  --totalTaskCount_;
  l.unlock();
  while (!tasks_.try_dequeue(task)) {
    waitSem_.wait();
    if (shouldStop()) {
      std::unique_lock<std::mutex> l2(mutex_);
      --idleCount_;
      ++totalTaskCount_;
      return nullptr;
    }
  }
  --idleCount_;
  // totalTaskCount_ doesn't change:
  // the decrement of idleCount_ and the dequeueing of a task cancel each other

  return task;
}

void ThreadManager::Impl::onTaskExpired(const Task& task) {
  ExpireCallback expireCallback;
  {
    std::unique_lock<std::mutex> l(mutex_);
    expiredCount_++;
    expireCallback = expireCallback_;
  }

  if (expireCallback) {
    // Expired callback should _not_ be called holding mutex_
    expireCallback(task.getRunnable());
  }
}

void ThreadManager::Impl::setExpireCallback(ExpireCallback expireCallback) {
  expireCallback_ = expireCallback;
}

void ThreadManager::Impl::setCodelCallback(ExpireCallback expireCallback) {
  codelCallback_ = expireCallback;
}

void ThreadManager::Impl::getStats(
    std::chrono::microseconds& waitTime,
    std::chrono::microseconds& runTime,
    int64_t maxItems) {
  folly::MSLGuard g(statsLock_);
  if (numTasks_) {
    if (numTasks_ >= maxItems) {
      waitingTimeUs_ /= numTasks_;
      executingTimeUs_ /= numTasks_;
      numTasks_ = 1;
    }
    waitTime = waitingTimeUs_ / numTasks_;
    runTime = executingTimeUs_ / numTasks_;
  } else {
    waitTime = std::chrono::microseconds::zero();
    runTime = std::chrono::microseconds::zero();
  }
}

void ThreadManager::Impl::reportTaskStats(
    const Task& task,
    const std::chrono::steady_clock::time_point& workBegin,
    const std::chrono::steady_clock::time_point& workEnd) {
  auto queueBegin = task.getQueueBeginTime();
  auto waitTime = workBegin - queueBegin;
  auto runTime = workEnd - workBegin;

  // Times in this USDT use granularity of std::chrono::steady_clock::duration,
  // which is platform dependent. On Facebook servers, the granularity is
  // nanoseconds. We explicitly do not perform any unit conversions to avoid
  // unneccessary costs and leave it to consumers of this data to know what
  // effective clock resolution is.
  FOLLY_SDT(
      thrift,
      thread_manager_task_stats,
      namePrefix_.c_str(),
      task.getContext() ? task.getContext()->getRootId() : 0,
      queueBegin.time_since_epoch().count(),
      waitTime.count(),
      runTime.count());

  if (enableTaskStats_) {
    folly::MSLGuard g(statsLock_);
    auto waitTimeUs =
        std::chrono::duration_cast<std::chrono::microseconds>(waitTime);
    auto runTimeUs =
        std::chrono::duration_cast<std::chrono::microseconds>(runTime);
    waitingTimeUs_ += waitTimeUs;
    executingTimeUs_ += runTimeUs;
    ++numTasks_;
  }

  // Optimistic check lock free
  if (ThreadManager::Impl::observer_) {
    // Hold lock to ensure that observer_ does not get deleted.
    folly::SharedMutex::ReadHolder g(ThreadManager::Impl::observerLock_);
    if (ThreadManager::Impl::observer_) {
      // Note: We are assuming the namePrefix_ does not change after the thread
      // is started.
      // TODO: enforce this.
      auto seriesName = folly::to<std::string>(namePrefix_, statContext());
      ThreadManager::Impl::observer_->postRun(
          task.getContext().get(),
          {seriesName, queueBegin, workBegin, workEnd});
    }
  }
}

void ThreadManager::Impl::enableCodel(bool enabled) {
  codelEnabled_ = enabled || FLAGS_codel_enabled;
}

folly::Codel* ThreadManager::Impl::getCodel() {
  return &codel_;
}

void ThreadManager::Impl::setupQueueObservers() {
  if (auto factory = folly::QueueObserverFactory::make(
          "tm." + (namePrefix_.empty() ? "unk" : namePrefix_),
          tasks_.priorities())) {
    queueObservers_.emplace(tasks_.priorities());
    for (size_t pri = 0; pri < tasks_.priorities(); ++pri) {
      queueObservers_->at(pri) = factory->create(pri);
    }
  }
}

class PriorityThreadManager::PriorityImpl
    : public PriorityThreadManager,
      public folly::DefaultKeepAliveExecutor {
 public:
  explicit PriorityImpl(
      const std::array<
          std::pair<std::shared_ptr<ThreadFactory>, size_t>,
          N_PRIORITIES>& factories,
      bool enableTaskStats = false) {
    executors_.reserve(N_PRIORITIES * N_SOURCES);
    for (int i = 0; i < N_PRIORITIES; i++) {
      auto m = std::make_unique<ThreadManager::Impl>(enableTaskStats);
      // for INTERNAL source, this is just a straight pass through
      executors_.emplace_back(m.get()).get_deleter().unown();
      for (int j = 1; j < N_SOURCES; j++) {
        auto wrapper =
            makeExecutor(static_cast<PRIORITY>(i), static_cast<Source>(j));
        executors_.emplace_back(wrapper.release());
      }
      m->threadFactory(factories[i].first);
      managers_[i] = std::move(m);
      counts_[i] = factories[i].second;
    }
  }

  ~PriorityImpl() override {
    joinKeepAliveOnce();
  }

  void start() override {
    Guard g(mutex_);
    for (int i = 0; i < N_PRIORITIES; i++) {
      if (managers_[i]->state() == STARTED) {
        continue;
      }
      managers_[i]->start();
      managers_[i]->addWorker(counts_[i]);
    }
  }

  void stop() override {
    Guard g(mutex_);
    joinKeepAliveOnce();
    for (auto& m : managers_) {
      m->stop();
    }
  }

  void join() override {
    Guard g(mutex_);
    joinKeepAliveOnce();
    for (auto& m : managers_) {
      m->join();
    }
  }

  std::string getNamePrefix() const override {
    return managers_[0]->getNamePrefix();
  }

  void setNamePrefix(const std::string& name) override {
    for (int i = 0; i < N_PRIORITIES; i++) {
      managers_[i]->setNamePrefix(folly::to<std::string>(name, "-pri", i));
    }
  }

  void addWorker(size_t value) override {
    addWorker(NORMAL, value);
  }

  void removeWorker(size_t value) override {
    removeWorker(NORMAL, value);
  }

  void addWorker(PRIORITY priority, size_t value) override {
    managers_[priority]->addWorker(value);
  }

  void removeWorker(PRIORITY priority, size_t value) override {
    managers_[priority]->removeWorker(value);
  }

  size_t workerCount(PRIORITY priority) override {
    return managers_[priority]->workerCount();
  }

  STATE state() const override {
    size_t started = 0;
    Guard g(mutex_);
    for (auto& m : managers_) {
      STATE cur_state = m->state();
      switch (cur_state) {
        case UNINITIALIZED:
        case STARTING:
        case JOINING:
        case STOPPING:
          return cur_state;
        case STARTED:
          started++;
          break;
        case STOPPED:
          break;
      }
    }
    if (started == 0) {
      return STOPPED;
    }
    return STARTED;
  }

  std::shared_ptr<ThreadFactory> threadFactory() const override {
    throw IllegalStateException("Not implemented");
    return std::shared_ptr<ThreadFactory>();
  }

  void threadFactory(std::shared_ptr<ThreadFactory> value) override {
    Guard g(mutex_);
    for (auto& m : managers_) {
      m->threadFactory(value);
    }
  }

  using PriorityThreadManager::add;
  using ThreadManager::add;
  void add(
      std::shared_ptr<Runnable> task,
      int64_t timeout,
      int64_t expiration,
      ThreadManager::Source source) noexcept override {
    add(PRIORITY::NORMAL, std::move(task), timeout, expiration, source);
  }

  void add(
      PRIORITY priority,
      std::shared_ptr<Runnable> task,
      int64_t timeout,
      int64_t expiration,
      ThreadManager::Source source) noexcept override {
    managers_[priority]->add(std::move(task), timeout, expiration, source);
  }

  void addWithPriorityAndSource(folly::Func f, PRIORITY pri, Source source) {
    managers_[pri]->add(FunctionRunner::create(std::move(f)), 0, 0, source);
  }

  KeepAlive<> getKeepAlive(ExecutionScope es, Source source) const override {
    size_t idx = es.getPriority() * N_SOURCES + static_cast<uint8_t>(source);
    DCHECK(idx < executors_.size());
    return getKeepAliveToken(*executors_[idx]);
  }

  /**
   * Implements folly::Executor::add()
   */
  void add(folly::Func f) override {
    add(FunctionRunner::create(std::move(f)));
  }

  /**
   * Implements folly::Executor::addWithPriority()
   * Maps executor priority task to respective PriorityThreadManager threads:
   *  >= 3 pri tasks to 'HIGH_IMPORTANT' threads,
   *  2 pri tasks to 'HIGH' threads,
   *  1 pri tasks to 'IMPORTANT' threads,
   *  0 pri tasks to 'NORMAL' threads,
   *  <= -1 pri tasks to 'BEST_EFFORT' threads,
   */
  void addWithPriority(folly::Func f, int8_t priority) override {
    auto prio = translatePriority(priority);
    add(prio, FunctionRunner::create(std::move(f)));
  }

  template <typename T>
  size_t sum(T method) const {
    size_t count = 0;
    for (const auto& m : managers_) {
      count += ((*m).*method)();
    }
    return count;
  }

  size_t idleWorkerCount() const override {
    return sum(&ThreadManager::idleWorkerCount);
  }

  size_t idleWorkerCount(PRIORITY priority) const override {
    return managers_[priority]->idleWorkerCount();
  }

  size_t workerCount() const override {
    return sum(&ThreadManager::workerCount);
  }

  size_t pendingTaskCount() const override {
    return sum(&ThreadManager::pendingTaskCount);
  }

  size_t pendingUpstreamTaskCount() const override {
    return sum(&ThreadManager::pendingUpstreamTaskCount);
  }

  size_t pendingTaskCount(PRIORITY priority) const override {
    return managers_[priority]->pendingTaskCount();
  }

  size_t totalTaskCount() const override {
    return sum(&ThreadManager::totalTaskCount);
  }

  size_t expiredTaskCount() override {
    return sum(&ThreadManager::expiredTaskCount);
  }

  void remove(std::shared_ptr<Runnable> /*task*/) override {
    throw IllegalStateException("Not implemented");
  }

  std::shared_ptr<Runnable> removeNextPending() override {
    throw IllegalStateException("Not implemented");
    return std::shared_ptr<Runnable>();
  }

  void clearPending() override {
    for (const auto& m : managers_) {
      m->clearPending();
    }
  }

  void setExpireCallback(ExpireCallback expireCallback) override {
    for (const auto& m : managers_) {
      m->setExpireCallback(expireCallback);
    }
  }

  void setCodelCallback(ExpireCallback expireCallback) override {
    for (const auto& m : managers_) {
      m->setCodelCallback(expireCallback);
    }
  }

  void setThreadInitCallback(InitCallback /*initCallback*/) override {
    throw IllegalStateException("Not implemented");
  }

  void enableCodel(bool enabled) override {
    for (const auto& m : managers_) {
      m->enableCodel(enabled);
    }
  }

  folly::Codel* getCodel() override {
    return getCodel(NORMAL);
  }

  folly::Codel* getCodel(PRIORITY priority) override {
    return managers_[priority]->getCodel();
  }

 private:
  void joinKeepAliveOnce() {
    if (!std::exchange(keepAliveJoined_, true)) {
      joinKeepAlive();
    }
  }

  std::unique_ptr<Executor> makeExecutor(PRIORITY pri, Source source) {
    return ExecutorWithSourceAndPriority<PriorityImpl>::create(
        pri, source, this);
  }

  std::unique_ptr<ThreadManager> managers_[N_PRIORITIES];
  size_t counts_[N_PRIORITIES];
  Mutex mutex_;
  std::vector<std::unique_ptr<Executor, Deleter>> executors_;
  bool keepAliveJoined_{false};
};

namespace {

class PriorityQueueThreadManager : public ThreadManager::Impl {
 public:
  typedef apache::thrift::concurrency::PRIORITY PRIORITY;
  explicit PriorityQueueThreadManager(
      size_t numThreads,
      bool enableTaskStats = false)
      : ThreadManager::Impl(enableTaskStats, N_PRIORITIES),
        numThreads_(numThreads) {
    for (int i = 0; i < N_PRIORITIES; i++) {
      for (int j = 0; j < N_SOURCES; j++) {
        executors_.emplace_back(
            makeExecutor(static_cast<PRIORITY>(i), static_cast<Source>(j)));
      }
    }
  }

  void join() override {
    ThreadManager::Impl::join();
  }

  using ThreadManager::add;
  using ThreadManager::Impl::add;

  void add(
      std::shared_ptr<Runnable> task,
      int64_t timeout,
      int64_t expiration,
      apache::thrift::concurrency::ThreadManager::Source source) noexcept
      override {
    ThreadManager::Impl::add(
        PRIORITY::NORMAL, std::move(task), timeout, expiration, source);
  }

  /**
   * Implements folly::Executor::add()
   */
  void add(folly::Func f) override {
    // We default adds of this kind to highest priority; as ThriftServer
    // doesn't use this itself, this is typically used by the application,
    // and we want to prioritize inflight requests over admitting new request.
    // arguably, we may even want a priority above the max we ever allow for
    // initial queueing
    ThreadManager::Impl::add(
        PRIORITY::HIGH_IMPORTANT,
        std::make_shared<FunctionRunner>(std::move(f)),
        0,
        0,
        apache::thrift::concurrency::ThreadManager::Source::INTERNAL);
  }

  /**
   * Implements folly::Executor::addWithPriority()
   */
  void addWithPriority(folly::Func f, int8_t priority) override {
    auto prio = translatePriority(priority);
    ThreadManager::Impl::add(
        prio,
        std::make_shared<FunctionRunner>(std::move(f)),
        0,
        0,
        apache::thrift::concurrency::ThreadManager::Source::INTERNAL);
  }

  uint8_t getNumPriorities() const override {
    return N_PRIORITIES;
  }

  void start() override {
    ThreadManager::Impl::start();
    ThreadManager::Impl::addWorker(numThreads_);
  }

  void addWithPriorityAndSource(folly::Func f, PRIORITY pri, Source source) {
    add(pri, std::make_shared<FunctionRunner>(std::move(f)), 0, 0, source);
  }

  KeepAlive<> getKeepAlive(ExecutionScope es, Source source) const override {
    size_t idx = es.getPriority() * N_SOURCES + static_cast<uint8_t>(source);
    DCHECK(idx < executors_.size());
    return getKeepAliveToken(*executors_[idx]);
  }

  void setNamePrefix(const std::string& name) override {
    // This isn't thread safe, but neither is PriorityThreadManager's version
    // This should only be called at initialization
    ThreadManager::Impl::setNamePrefix(name);
    for (int i = 0; i < N_PRIORITIES; i++) {
      statContexts_[i] = folly::to<std::string>(name, "-pri", i);
    }
  }

  using Task = typename ThreadManager::Impl::Task;

  std::string statContext(PRIORITY p = concurrency::PRIORITY::NORMAL) override {
    return statContexts_[p];
  }

 private:
  std::unique_ptr<Executor> makeExecutor(PRIORITY pri, Source source) {
    return ExecutorWithSourceAndPriority<PriorityQueueThreadManager>::create(
        pri, source, this);
  }

  size_t numThreads_;
  std::string statContexts_[N_PRIORITIES];
  std::vector<std::unique_ptr<Executor>> executors_;
};

template <size_t N, typename T>
std::array<T, N> fillArrayWith(const T& t) {
  std::array<T, N> result;
  result.fill(t);
  return result;
}

constexpr auto N_SOURCES = ThreadManager::N_SOURCES;
int idxFromPriSrc(int pri, int source) {
  DCHECK(pri < N_PRIORITIES);
  return pri * N_SOURCES + source;
}

int idxFromPriSrc(PRIORITY pri, ThreadManager::Source source) {
  return idxFromPriSrc(static_cast<int>(pri), static_cast<int>(source));
}

template <typename F>
void forEachThreadManager(
    const std::array<folly::Executor*, N_PRIORITIES * N_SOURCES>& executors,
    F&& func) {
  for (size_t i = 0; i < N_PRIORITIES; i++) {
    if (auto tm = dynamic_cast<ThreadManager*>(executors[i * N_SOURCES])) {
      func(tm, static_cast<PRIORITY>(i));
    }
  }
}

} // namespace

ThreadManagerExecutorAdapter::ThreadManagerExecutorAdapter(
    std::shared_ptr<folly::Executor> exe)
    : ThreadManagerExecutorAdapter(fillArrayWith<N_PRIORITIES>(exe)) {}

ThreadManagerExecutorAdapter::ThreadManagerExecutorAdapter(
    folly::Executor::KeepAlive<> ka)
    : ThreadManagerExecutorAdapter(
          std::make_shared<folly::VirtualExecutor>(std::move(ka))) {}

ThreadManagerExecutorAdapter::ThreadManagerExecutorAdapter(
    std::array<std::shared_ptr<folly::Executor>, N_PRIORITIES> executors) {
  for (size_t i = 0; i < executors.size(); i++) {
    auto& executor = executors[i];
    if (!executor) {
      auto tm = ThreadManager::newSimpleThreadManager(2);
      executor = tm;
      for (int j = 0; j < N_SOURCES; j++) {
        executors_[idxFromPriSrc(i, j)] =
            tm->getKeepAlive(
                  static_cast<PRIORITY>(0),
                  static_cast<ThreadManager::Source>(j))
                .get();
      }
    } else {
      executors_[idxFromPriSrc(i, 0)] = executor.get();
      std::unique_ptr<folly::MeteredExecutor> adapter;
      for (int j = 1; j < N_SOURCES; j++) {
        if (!adapter) {
          adapter = std::make_unique<folly::MeteredExecutor>(executor.get());
        } else {
          adapter =
              std::make_unique<folly::MeteredExecutor>(std::move(adapter));
        }
        executors_[idxFromPriSrc(i, j)] = adapter.get();
      }
      owning_.push_back(folly::to_shared_ptr(std::move(adapter)));
    }
    owning_.emplace_back(std::move(executor));
  }
}

void ThreadManagerExecutorAdapter::join() {
  forEachThreadManager(executors_, [](auto tm, auto) { tm->join(); });
}

void ThreadManagerExecutorAdapter::start() {
  forEachThreadManager(executors_, [](auto tm, auto) { tm->start(); });
}

void ThreadManagerExecutorAdapter::stop() {
  forEachThreadManager(executors_, [](auto tm, auto) { tm->stop(); });
}

void ThreadManagerExecutorAdapter::addWorker(size_t value) {
  forEachThreadManager(
      executors_, [value](auto tm, auto) { tm->addWorker(value); });
}

void ThreadManagerExecutorAdapter::removeWorker(size_t value) {
  forEachThreadManager(
      executors_, [value](auto tm, auto) { tm->removeWorker(value); });
}

std::shared_ptr<ThreadFactory> ThreadManagerExecutorAdapter::threadFactory()
    const {
  return nullptr;
}

void ThreadManagerExecutorAdapter::threadFactory(
    std::shared_ptr<ThreadFactory> value) {
  forEachThreadManager(
      executors_, [=](auto tm, auto) { tm->threadFactory(value); });
}

std::string ThreadManagerExecutorAdapter::getNamePrefix() const {
  return "";
}

void ThreadManagerExecutorAdapter::setNamePrefix(const std::string& name) {
  forEachThreadManager(executors_, [&](auto tm, auto pri) {
    tm->setNamePrefix(name + "-" + folly::to<std::string>(pri));
  });
}

void ThreadManagerExecutorAdapter::add(
    std::shared_ptr<Runnable> task,
    int64_t /*timeout*/,
    int64_t /*expiration*/,
    ThreadManager::Source source) noexcept {
  getKeepAlive(PRIORITY::NORMAL, source)->add([=] { task->run(); });
}

void ThreadManagerExecutorAdapter::add(folly::Func f) {
  getKeepAlive(PRIORITY::NORMAL, Source::INTERNAL)->add(std::move(f));
}

folly::Executor::KeepAlive<> ThreadManagerExecutorAdapter::getKeepAlive(
    ExecutionScope es,
    Source source) const {
  return getKeepAliveToken(executors_[idxFromPriSrc(es.getPriority(), source)]);
}

void ThreadManager::setObserver(
    std::shared_ptr<ThreadManager::Observer> observer) {
  {
    folly::SharedMutex::WriteHolder g(observerLock_);
    observer_.swap(observer);
  }
}

std::shared_ptr<ThreadManager> ThreadManager::newSimpleThreadManager(
    size_t count,
    bool enableTaskStats) {
  auto tm = std::make_shared<SimpleThreadManagerImpl>(count, enableTaskStats);
  tm->threadFactory(Factory(PosixThreadFactory::NORMAL_PRI));
  return tm;
}

std::shared_ptr<ThreadManager> ThreadManager::newSimpleThreadManager(
    const std::string& name,
    size_t count,
    bool enableTaskStats) {
  auto simpleThreadManager =
      std::make_shared<SimpleThreadManagerImpl>(count, enableTaskStats);
  simpleThreadManager->setNamePrefix(name);
  return simpleThreadManager;
}

std::shared_ptr<ThreadManager> ThreadManager::newPriorityQueueThreadManager(
    size_t numThreads,
    bool enableTaskStats) {
  auto tm =
      std::make_shared<PriorityQueueThreadManager>(numThreads, enableTaskStats);
  tm->threadFactory(Factory(PosixThreadFactory::NORMAL_PRI));
  return tm;
}

std::shared_ptr<PriorityThreadManager>
PriorityThreadManager::newPriorityThreadManager(
    const std::array<
        std::pair<std::shared_ptr<ThreadFactory>, size_t>,
        N_PRIORITIES>& factories,
    bool enableTaskStats) {
  auto copy = factories;
  if (copy[PRIORITY::NORMAL].second < NORMAL_PRIORITY_MINIMUM_THREADS) {
    LOG(INFO) << "Creating minimum threads of NORMAL priority: "
              << NORMAL_PRIORITY_MINIMUM_THREADS;
    copy[PRIORITY::NORMAL].second = NORMAL_PRIORITY_MINIMUM_THREADS;
  }
  return std::make_shared<PriorityThreadManager::PriorityImpl>(
      copy, enableTaskStats);
}

std::shared_ptr<PriorityThreadManager>
PriorityThreadManager::newPriorityThreadManager(
    const std::array<size_t, N_PRIORITIES>& counts,
    bool enableTaskStats) {
  static_assert(N_PRIORITIES == 5, "Implementation is out-of-date");
  // Note that priorities for HIGH and IMPORTANT are the same, the difference
  // is in the number of threads.
  const std::array<
      std::pair<std::shared_ptr<ThreadFactory>, size_t>,
      N_PRIORITIES>
      factories{{
          {Factory(PosixThreadFactory::HIGHER_PRI),
           counts[PRIORITY::HIGH_IMPORTANT]},
          {Factory(PosixThreadFactory::HIGH_PRI), counts[PRIORITY::HIGH]},
          {Factory(PosixThreadFactory::HIGH_PRI), counts[PRIORITY::IMPORTANT]},
          {Factory(PosixThreadFactory::NORMAL_PRI), counts[PRIORITY::NORMAL]},
          {Factory(PosixThreadFactory::LOW_PRI), counts[PRIORITY::BEST_EFFORT]},
      }};
  return newPriorityThreadManager(factories, enableTaskStats);
}

std::shared_ptr<PriorityThreadManager>
PriorityThreadManager::newPriorityThreadManager(
    size_t normalThreadsCount,
    bool enableTaskStats) {
  return newPriorityThreadManager(
      {{2, 2, 2, normalThreadsCount, 2}}, enableTaskStats);
}

folly::SharedMutex ThreadManager::observerLock_;
std::shared_ptr<ThreadManager::Observer> ThreadManager::observer_;

} // namespace concurrency
} // namespace thrift
} // namespace apache
