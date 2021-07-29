/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/included_types.h"
#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/namespaced_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {

class MyServiceAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "MyService";
  }


  virtual void first(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void first(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void firstImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback);
 public:

  virtual void sync_first(::cpp2::annotated_inline_string& _return);
  virtual void sync_first(apache::thrift::RpcOptions& rpcOptions, ::cpp2::annotated_inline_string& _return);

  virtual folly::Future<::cpp2::annotated_inline_string> future_first();
  virtual folly::SemiFuture<::cpp2::annotated_inline_string> semifuture_first();
  virtual folly::Future<::cpp2::annotated_inline_string> future_first(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<::cpp2::annotated_inline_string> semifuture_first(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<::cpp2::annotated_inline_string, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_first(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<::cpp2::annotated_inline_string, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_first(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<::cpp2::annotated_inline_string> co_first() {
    return co_first<false>(nullptr);
  }
  template <int = 0>
  folly::coro::Task<::cpp2::annotated_inline_string> co_first(apache::thrift::RpcOptions& rpcOptions) {
    return co_first<true>(&rpcOptions);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::cpp2::annotated_inline_string> co_first(apache::thrift::RpcOptions* rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = firstCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      firstImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    } else {
      firstImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    ::cpp2::annotated_inline_string _return;
    if (auto ew = recv_wrapped_first(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void first(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);


  static folly::exception_wrapper recv_wrapped_first(::cpp2::annotated_inline_string& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_first(::cpp2::annotated_inline_string& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_first(::cpp2::annotated_inline_string& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_first(::cpp2::annotated_inline_string& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void firstT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> firstCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
  virtual void second(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int64_t p_count);
  virtual void second(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int64_t p_count);
 protected:
  void secondImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int64_t p_count);
 public:

  virtual bool sync_second(::std::int64_t p_count);
  virtual bool sync_second(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_count);

  virtual folly::Future<bool> future_second(::std::int64_t p_count);
  virtual folly::SemiFuture<bool> semifuture_second(::std::int64_t p_count);
  virtual folly::Future<bool> future_second(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_count);
  virtual folly::SemiFuture<bool> semifuture_second(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_count);
  virtual folly::Future<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_second(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_count);
  virtual folly::SemiFuture<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_second(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_count);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<bool> co_second(::std::int64_t p_count) {
    return co_second<false>(nullptr, p_count);
  }
  template <int = 0>
  folly::coro::Task<bool> co_second(apache::thrift::RpcOptions& rpcOptions, ::std::int64_t p_count) {
    return co_second<true>(&rpcOptions, p_count);
  }
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<bool> co_second(apache::thrift::RpcOptions* rpcOptions, ::std::int64_t p_count) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientSyncCallback<false> callback(&returnState);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = secondCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static const apache::thrift::RpcOptions defaultRpcOptions;
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if constexpr (hasRpcOptions) {
      secondImpl(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_count);
    } else {
      secondImpl(defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_count);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    bool _return;
    if (auto ew = recv_wrapped_second(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  virtual void second(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int64_t p_count);


  static folly::exception_wrapper recv_wrapped_second(bool& _return, ::apache::thrift::ClientReceiveState& state);
  static bool recv_second(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual bool recv_instance_second(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_second(bool& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void secondT(Protocol_* prot, const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int64_t p_count);
  std::pair<std::unique_ptr<::apache::thrift::ContextStack>, std::shared_ptr<::apache::thrift::transport::THeader>> secondCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
};

} // cpp2
