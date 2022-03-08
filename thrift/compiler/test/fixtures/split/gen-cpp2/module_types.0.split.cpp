/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/split/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/split/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/split/gen-cpp2/module_data.h"


namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::MyEnum>::size;
folly::Range<::cpp2::MyEnum const*> const TEnumTraits<::cpp2::MyEnum>::values = folly::range(TEnumDataStorage<::cpp2::MyEnum>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::MyEnum>::names = folly::range(TEnumDataStorage<::cpp2::MyEnum>::names);

char const* TEnumTraits<::cpp2::MyEnum>::findName(type value) {
  return ::apache::thrift::detail::st::enum_find_name(value);
}

bool TEnumTraits<::cpp2::MyEnum>::findValue(char const* name, type* out) {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}

}} // apache::thrift

namespace cpp2 {
#ifndef ANDROID
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Wdeprecated-declarations")
const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES = _MyEnum_EnumMapFactory::makeValuesToNamesMap();
const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES = _MyEnum_EnumMapFactory::makeNamesToValuesMap();
FOLLY_POP_WARNING
#endif
} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

MyStruct::MyStruct(const MyStruct&) = default;
MyStruct& MyStruct::operator=(const MyStruct&) = default;
MyStruct::MyStruct() :
      __fbthrift_field_MyIntField(),
      __fbthrift_field_myEnum(),
      __fbthrift_field_oneway(),
      __fbthrift_field_readonly(),
      __fbthrift_field_idempotent() {
}


MyStruct::~MyStruct() {}

MyStruct::MyStruct(MyStruct&& other) noexcept  :
    __fbthrift_field_MyIntField(std::move(other.__fbthrift_field_MyIntField)),
    __fbthrift_field_MyStringField(std::move(other.__fbthrift_field_MyStringField)),
    __fbthrift_field_MyDataField(std::move(other.__fbthrift_field_MyDataField)),
    __fbthrift_field_myEnum(std::move(other.__fbthrift_field_myEnum)),
    __fbthrift_field_oneway(std::move(other.__fbthrift_field_oneway)),
    __fbthrift_field_readonly(std::move(other.__fbthrift_field_readonly)),
    __fbthrift_field_idempotent(std::move(other.__fbthrift_field_idempotent)),
    __isset(other.__isset) {
}

MyStruct& MyStruct::operator=(FOLLY_MAYBE_UNUSED MyStruct&& other) noexcept {
    this->__fbthrift_field_MyIntField = std::move(other.__fbthrift_field_MyIntField);
    this->__fbthrift_field_MyStringField = std::move(other.__fbthrift_field_MyStringField);
    this->__fbthrift_field_MyDataField = std::move(other.__fbthrift_field_MyDataField);
    this->__fbthrift_field_myEnum = std::move(other.__fbthrift_field_myEnum);
    this->__fbthrift_field_oneway = std::move(other.__fbthrift_field_oneway);
    this->__fbthrift_field_readonly = std::move(other.__fbthrift_field_readonly);
    this->__fbthrift_field_idempotent = std::move(other.__fbthrift_field_idempotent);
    __isset = other.__isset;
    return *this;
}


MyStruct::MyStruct(apache::thrift::FragileConstructor, ::std::int64_t MyIntField__arg, ::std::string MyStringField__arg, ::cpp2::MyDataItem MyDataField__arg, ::cpp2::MyEnum myEnum__arg, bool oneway__arg, bool readonly__arg, bool idempotent__arg) :
    __fbthrift_field_MyIntField(std::move(MyIntField__arg)),
    __fbthrift_field_MyStringField(std::move(MyStringField__arg)),
    __fbthrift_field_MyDataField(std::move(MyDataField__arg)),
    __fbthrift_field_myEnum(std::move(myEnum__arg)),
    __fbthrift_field_oneway(std::move(oneway__arg)),
    __fbthrift_field_readonly(std::move(readonly__arg)),
    __fbthrift_field_idempotent(std::move(idempotent__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
  __isset.set(folly::index_constant<3>(), true);
  __isset.set(folly::index_constant<4>(), true);
  __isset.set(folly::index_constant<5>(), true);
  __isset.set(folly::index_constant<6>(), true);
}


void MyStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_MyIntField = ::std::int64_t();
  this->__fbthrift_field_MyStringField = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_myEnum = ::cpp2::MyEnum();
  this->__fbthrift_field_oneway = bool();
  this->__fbthrift_field_readonly = bool();
  this->__fbthrift_field_idempotent = bool();
  __isset = {};
}

bool MyStruct::__fbthrift_is_empty() const {
  return false;
}

bool MyStruct::operator==(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.MyIntField_ref() == rhs.MyIntField_ref())) {
    return false;
  }
  if (!(lhs.MyStringField_ref() == rhs.MyStringField_ref())) {
    return false;
  }
  if (!(lhs.MyDataField_ref() == rhs.MyDataField_ref())) {
    return false;
  }
  if (!(lhs.myEnum_ref() == rhs.myEnum_ref())) {
    return false;
  }
  if (!(lhs.oneway_ref() == rhs.oneway_ref())) {
    return false;
  }
  if (!(lhs.readonly_ref() == rhs.readonly_ref())) {
    return false;
  }
  if (!(lhs.idempotent_ref() == rhs.idempotent_ref())) {
    return false;
  }
  return true;
}

bool MyStruct::operator<(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.MyIntField_ref() == rhs.MyIntField_ref())) {
    return lhs.MyIntField_ref() < rhs.MyIntField_ref();
  }
  if (!(lhs.MyStringField_ref() == rhs.MyStringField_ref())) {
    return lhs.MyStringField_ref() < rhs.MyStringField_ref();
  }
  if (!(lhs.MyDataField_ref() == rhs.MyDataField_ref())) {
    return lhs.MyDataField_ref() < rhs.MyDataField_ref();
  }
  if (!(lhs.myEnum_ref() == rhs.myEnum_ref())) {
    return lhs.myEnum_ref() < rhs.myEnum_ref();
  }
  if (!(lhs.oneway_ref() == rhs.oneway_ref())) {
    return lhs.oneway_ref() < rhs.oneway_ref();
  }
  if (!(lhs.readonly_ref() == rhs.readonly_ref())) {
    return lhs.readonly_ref() < rhs.readonly_ref();
  }
  if (!(lhs.idempotent_ref() == rhs.idempotent_ref())) {
    return lhs.idempotent_ref() < rhs.idempotent_ref();
  }
  return false;
}

const ::cpp2::MyDataItem& MyStruct::get_MyDataField() const& {
  return __fbthrift_field_MyDataField;
}

::cpp2::MyDataItem MyStruct::get_MyDataField() && {
  return std::move(__fbthrift_field_MyDataField);
}


void swap(MyStruct& a, MyStruct& b) {
  using ::std::swap;
  swap(a.MyIntField_ref().value(), b.MyIntField_ref().value());
  swap(a.MyStringField_ref().value(), b.MyStringField_ref().value());
  swap(a.MyDataField_ref().value(), b.MyDataField_ref().value());
  swap(a.myEnum_ref().value(), b.myEnum_ref().value());
  swap(a.oneway_ref().value(), b.oneway_ref().value());
  swap(a.readonly_ref().value(), b.readonly_ref().value());
  swap(a.idempotent_ref().value(), b.idempotent_ref().value());
  swap(a.__isset, b.__isset);
}

template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        MyStruct,
        ::apache::thrift::type_class::structure,
        ::cpp2::MyDataItem>,
    "inconsistent use of json option");

static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        MyStruct,
        ::apache::thrift::type_class::structure,
        ::cpp2::MyDataItem>,
    "inconsistent use of nimble option");

} // cpp2

namespace cpp2 { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}} // cpp2
