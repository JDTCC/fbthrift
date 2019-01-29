/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/MyServicePrioChild.h"
#include "src/gen-cpp2/MyServicePrioChild.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> MyServicePrioChildSvIf::getProcessor() {
  return std::make_unique<MyServicePrioChildAsyncProcessor>(this);
}

void MyServicePrioChildSvIf::pang() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("pang");
}

folly::SemiFuture<folly::Unit> MyServicePrioChildSvIf::semifuture_pang() {
  return apache::thrift::detail::si::semifuture([&] { return pang(); });
}

folly::Future<folly::Unit> MyServicePrioChildSvIf::future_pang() {
  return apache::thrift::detail::si::future(semifuture_pang(), getThreadManager());
}


void MyServicePrioChildSvIf::async_tm_pang(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_pang(); });
}

void MyServicePrioChildSvNull::pang() {
  return;
}

const char* MyServicePrioChildAsyncProcessor::getServiceName() {
  return "MyServicePrioChild";
}

folly::Optional<std::string> MyServicePrioChildAsyncProcessor::getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) {
  return apache::thrift::detail::ap::get_cache_key(buf, protType, cacheKeyMap_);
}

void MyServicePrioChildAsyncProcessor::process(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(buf), protType, context, eb, tm);
}

bool MyServicePrioChildAsyncProcessor::isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) {
  return apache::thrift::detail::ap::is_oneway_method(buf, header, onewayMethods_);
}

std::unordered_set<std::string> MyServicePrioChildAsyncProcessor::onewayMethods_ {};
std::unordered_map<std::string, int16_t> MyServicePrioChildAsyncProcessor::cacheKeyMap_ {};
const MyServicePrioChildAsyncProcessor::BinaryProtocolProcessMap& MyServicePrioChildAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const MyServicePrioChildAsyncProcessor::BinaryProtocolProcessMap MyServicePrioChildAsyncProcessor::binaryProcessMap_ {
  {"pang", &MyServicePrioChildAsyncProcessor::_processInThread_pang<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const MyServicePrioChildAsyncProcessor::CompactProtocolProcessMap& MyServicePrioChildAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const MyServicePrioChildAsyncProcessor::CompactProtocolProcessMap MyServicePrioChildAsyncProcessor::compactProcessMap_ {
  {"pang", &MyServicePrioChildAsyncProcessor::_processInThread_pang<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
