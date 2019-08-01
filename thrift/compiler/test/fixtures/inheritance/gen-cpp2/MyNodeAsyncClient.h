/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyRootAsyncClient.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {

class MyNodeAsyncClient : public ::cpp2::MyRootAsyncClient {
 public:
  using ::cpp2::MyRootAsyncClient::MyRootAsyncClient;

  char const* getServiceName() const noexcept override {
    return "MyNode";
  }

  virtual void do_mid(std::unique_ptr<apache::thrift::RequestCallback> callback);
  virtual void do_mid(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 private:
  void do_midImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
  virtual void sync_do_mid();
  virtual void sync_do_mid(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<folly::Unit> future_do_mid();
  virtual folly::SemiFuture<folly::Unit> semifuture_do_mid();
  virtual folly::Future<folly::Unit> future_do_mid(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<folly::Unit> semifuture_do_mid(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_do_mid(apache::thrift::RpcOptions& rpcOptions);
  virtual folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_do_mid(apache::thrift::RpcOptions& rpcOptions);
#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_do_mid() {
    co_await semifuture_do_mid();
  }
#endif // FOLLY_HAS_COROUTINES
  virtual void do_mid(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);
  static folly::exception_wrapper recv_wrapped_do_mid(::apache::thrift::ClientReceiveState& state);
  static void recv_do_mid(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_do_mid(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_do_mid(::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void do_midT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback);
 public:
};

} // cpp2
