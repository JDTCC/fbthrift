/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/MyLeaf.h"
#include "src/gen-cpp2/MyLeaf.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> MyLeafSvIf::getProcessor() {
  return std::make_unique<MyLeafAsyncProcessor>(this);
}

void MyLeafSvIf::do_leaf() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("do_leaf");
}

folly::SemiFuture<folly::Unit> MyLeafSvIf::semifuture_do_leaf() {
  return apache::thrift::detail::si::semifuture([&] { return do_leaf(); });
}

folly::Future<folly::Unit> MyLeafSvIf::future_do_leaf() {
  return apache::thrift::detail::si::future(semifuture_do_leaf(), getThreadManager());
}


void MyLeafSvIf::async_tm_do_leaf(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_do_leaf(); });
}

void MyLeafSvNull::do_leaf() {
  return;
}

const char* MyLeafAsyncProcessor::getServiceName() {
  return "MyLeaf";
}

folly::Optional<std::string> MyLeafAsyncProcessor::getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) {
  return apache::thrift::detail::ap::get_cache_key(buf, protType, cacheKeyMap_);
}

void MyLeafAsyncProcessor::process(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(buf), protType, context, eb, tm);
}

bool MyLeafAsyncProcessor::isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) {
  return apache::thrift::detail::ap::is_oneway_method(buf, header, onewayMethods_);
}

std::unordered_set<std::string> MyLeafAsyncProcessor::onewayMethods_ {};
std::unordered_map<std::string, int16_t> MyLeafAsyncProcessor::cacheKeyMap_ {};
const MyLeafAsyncProcessor::BinaryProtocolProcessMap& MyLeafAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const MyLeafAsyncProcessor::BinaryProtocolProcessMap MyLeafAsyncProcessor::binaryProcessMap_ {
  {"do_leaf", &MyLeafAsyncProcessor::_processInThread_do_leaf<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const MyLeafAsyncProcessor::CompactProtocolProcessMap& MyLeafAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const MyLeafAsyncProcessor::CompactProtocolProcessMap MyLeafAsyncProcessor::compactProcessMap_ {
  {"do_leaf", &MyLeafAsyncProcessor::_processInThread_do_leaf<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
