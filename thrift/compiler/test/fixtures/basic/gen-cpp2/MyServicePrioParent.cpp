/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/MyServicePrioParent.h"
#include "src/gen-cpp2/MyServicePrioParent.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> MyServicePrioParentSvIf::getProcessor() {
  return std::make_unique<MyServicePrioParentAsyncProcessor>(this);
}

void MyServicePrioParentSvIf::ping() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("ping");
}

folly::SemiFuture<folly::Unit> MyServicePrioParentSvIf::semifuture_ping() {
  return apache::thrift::detail::si::semifuture([&] { return ping(); });
}

folly::Future<folly::Unit> MyServicePrioParentSvIf::future_ping() {
  return apache::thrift::detail::si::future(semifuture_ping(), getThreadManager());
}


void MyServicePrioParentSvIf::async_tm_ping(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_ping(); });
}

void MyServicePrioParentSvIf::pong() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("pong");
}

folly::SemiFuture<folly::Unit> MyServicePrioParentSvIf::semifuture_pong() {
  return apache::thrift::detail::si::semifuture([&] { return pong(); });
}

folly::Future<folly::Unit> MyServicePrioParentSvIf::future_pong() {
  return apache::thrift::detail::si::future(semifuture_pong(), getThreadManager());
}


void MyServicePrioParentSvIf::async_tm_pong(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_pong(); });
}

void MyServicePrioParentSvNull::ping() {
  return;
}

void MyServicePrioParentSvNull::pong() {
  return;
}

const char* MyServicePrioParentAsyncProcessor::getServiceName() {
  return "MyServicePrioParent";
}

folly::Optional<std::string> MyServicePrioParentAsyncProcessor::getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) {
  return apache::thrift::detail::ap::get_cache_key(buf, protType, cacheKeyMap_);
}

void MyServicePrioParentAsyncProcessor::process(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(buf), protType, context, eb, tm);
}

bool MyServicePrioParentAsyncProcessor::isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) {
  return apache::thrift::detail::ap::is_oneway_method(buf, header, onewayMethods_);
}

std::unordered_set<std::string> MyServicePrioParentAsyncProcessor::onewayMethods_ {};
std::unordered_map<std::string, int16_t> MyServicePrioParentAsyncProcessor::cacheKeyMap_ {};
const MyServicePrioParentAsyncProcessor::BinaryProtocolProcessMap& MyServicePrioParentAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const MyServicePrioParentAsyncProcessor::BinaryProtocolProcessMap MyServicePrioParentAsyncProcessor::binaryProcessMap_ {
  {"ping", &MyServicePrioParentAsyncProcessor::_processInThread_ping<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"pong", &MyServicePrioParentAsyncProcessor::_processInThread_pong<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const MyServicePrioParentAsyncProcessor::CompactProtocolProcessMap& MyServicePrioParentAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const MyServicePrioParentAsyncProcessor::CompactProtocolProcessMap MyServicePrioParentAsyncProcessor::compactProcessMap_ {
  {"ping", &MyServicePrioParentAsyncProcessor::_processInThread_ping<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"pong", &MyServicePrioParentAsyncProcessor::_processInThread_pong<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
