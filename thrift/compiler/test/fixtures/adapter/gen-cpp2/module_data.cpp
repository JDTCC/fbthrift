/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/adapter/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/module_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

#if defined(__GNUC__) && defined(__linux__) && !FOLLY_MOBILE
// This attribute is applied to the static data members to ensure that they are
// not stripped from the compiled binary, in order to keep them available for
// use by debuggers at runtime.
//
// The attribute works by forcing all of the data members (both used and unused
// ones) into the same section. This stops the linker from stripping the unused
// data, as it works on a per-section basis and only removes sections if they
// are entirely unused.
#define THRIFT_DATA_SECTION [[gnu::section(".rodata.thrift.data")]]
#else
#define THRIFT_DATA_SECTION
#endif

namespace apache {
namespace thrift {

THRIFT_DATA_SECTION const std::array<::facebook::thrift::test::ThriftAdaptedEnum, 2> TEnumDataStorage<::facebook::thrift::test::ThriftAdaptedEnum>::values = {{
  type::Zero,
  type::One,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TEnumDataStorage<::facebook::thrift::test::ThriftAdaptedEnum>::names = {{
  "Zero",
  "One",
}};

THRIFT_DATA_SECTION const std::array<::facebook::thrift::test::Baz::Type, 5> TEnumDataStorage<::facebook::thrift::test::Baz::Type>::values = {{
  type::intField,
  type::setField,
  type::mapField,
  type::binaryField,
  type::longField,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 5> TEnumDataStorage<::facebook::thrift::test::Baz::Type>::names = {{
  "intField",
  "setField",
  "mapField",
  "binaryField",
  "longField",
}};

THRIFT_DATA_SECTION const std::array<::facebook::thrift::test::ThriftAdaptTestUnion::Type, 2> TEnumDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion::Type>::values = {{
  type::delay,
  type::custom,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TEnumDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion::Type>::names = {{
  "delay",
  "custom",
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::MyAnnotation>::fields_names = {{
  "signature",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::MyAnnotation>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::MyAnnotation>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::MyAnnotation>::storage_names = {{
  "__fbthrift_field_signature",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::MyAnnotation>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 11> TStructDataStorage<::facebook::thrift::test::Foo>::fields_names = {{
  "intField",
  "optionalIntField",
  "intFieldWithDefault",
  "setField",
  "optionalSetField",
  "mapField",
  "optionalMapField",
  "binaryField",
  "longField",
  "adaptedLongField",
  "doubleAdaptedField",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 11> TStructDataStorage<::facebook::thrift::test::Foo>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 11> TStructDataStorage<::facebook::thrift::test::Foo>::fields_types = {{
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_SET,
  TType::T_SET,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_STRING,
  TType::T_I64,
  TType::T_I64,
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 11> TStructDataStorage<::facebook::thrift::test::Foo>::storage_names = {{
  "__fbthrift_field_intField",
  "__fbthrift_field_optionalIntField",
  "__fbthrift_field_intFieldWithDefault",
  "__fbthrift_field_setField",
  "__fbthrift_field_optionalSetField",
  "__fbthrift_field_mapField",
  "__fbthrift_field_optionalMapField",
  "__fbthrift_field_binaryField",
  "__fbthrift_field_longField",
  "__fbthrift_field_adaptedLongField",
  "__fbthrift_field_doubleAdaptedField",
}};
THRIFT_DATA_SECTION const std::array<int, 11> TStructDataStorage<::facebook::thrift::test::Foo>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 5> TStructDataStorage<::facebook::thrift::test::Baz>::fields_names = {{
  "intField",
  "setField",
  "mapField",
  "binaryField",
  "longField",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 5> TStructDataStorage<::facebook::thrift::test::Baz>::fields_ids = {{
  1,
  4,
  6,
  8,
  9,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 5> TStructDataStorage<::facebook::thrift::test::Baz>::fields_types = {{
  TType::T_I32,
  TType::T_SET,
  TType::T_MAP,
  TType::T_STRING,
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 5> TStructDataStorage<::facebook::thrift::test::Baz>::storage_names = {{
  "intField",
  "setField",
  "mapField",
  "binaryField",
  "longField",
}};
THRIFT_DATA_SECTION const std::array<int, 5> TStructDataStorage<::facebook::thrift::test::Baz>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 7> TStructDataStorage<::facebook::thrift::test::Bar>::fields_names = {{
  "structField",
  "optionalStructField",
  "structListField",
  "optionalStructListField",
  "unionField",
  "optionalUnionField",
  "adaptedStructField",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 7> TStructDataStorage<::facebook::thrift::test::Bar>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 7> TStructDataStorage<::facebook::thrift::test::Bar>::fields_types = {{
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 7> TStructDataStorage<::facebook::thrift::test::Bar>::storage_names = {{
  "__fbthrift_field_structField",
  "__fbthrift_field_optionalStructField",
  "__fbthrift_field_structListField",
  "__fbthrift_field_optionalStructListField",
  "__fbthrift_field_unionField",
  "__fbthrift_field_optionalUnionField",
  "__fbthrift_field_adaptedStructField",
}};
THRIFT_DATA_SECTION const std::array<int, 7> TStructDataStorage<::facebook::thrift::test::Bar>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdapted>::fields_names = {{
  "field",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdapted>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdapted>::fields_types = {{
  TType::T_I32,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdapted>::storage_names = {{
  "__fbthrift_field_field",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdapted>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 5> TStructDataStorage<::facebook::thrift::test::StructWithFieldAdapter>::fields_names = {{
  "field",
  "shared_field",
  "opt_shared_field",
  "opt_boxed_field",
  "boxed_field",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 5> TStructDataStorage<::facebook::thrift::test::StructWithFieldAdapter>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 5> TStructDataStorage<::facebook::thrift::test::StructWithFieldAdapter>::fields_types = {{
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 5> TStructDataStorage<::facebook::thrift::test::StructWithFieldAdapter>::storage_names = {{
  "__fbthrift_field_field",
  "__fbthrift_field_shared_field",
  "__fbthrift_field_opt_shared_field",
  "__fbthrift_field_opt_boxed_field",
  "__fbthrift_field_boxed_field",
}};
THRIFT_DATA_SECTION const std::array<int, 5> TStructDataStorage<::facebook::thrift::test::StructWithFieldAdapter>::isset_indexes = {{
  0,
  -1,
  -1,
  -1,
  -1,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 3> TStructDataStorage<::facebook::thrift::test::TerseAdaptedFields>::fields_names = {{
  "int_field",
  "string_field",
  "set_field",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 3> TStructDataStorage<::facebook::thrift::test::TerseAdaptedFields>::fields_ids = {{
  1,
  2,
  3,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 3> TStructDataStorage<::facebook::thrift::test::TerseAdaptedFields>::fields_types = {{
  TType::T_I32,
  TType::T_STRING,
  TType::T_SET,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 3> TStructDataStorage<::facebook::thrift::test::TerseAdaptedFields>::storage_names = {{
  "__fbthrift_field_int_field",
  "__fbthrift_field_string_field",
  "__fbthrift_field_set_field",
}};
THRIFT_DATA_SECTION const std::array<int, 3> TStructDataStorage<::facebook::thrift::test::TerseAdaptedFields>::isset_indexes = {{
  -1,
  -1,
  -1,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::B>::fields_names = {{
  "a",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::B>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::B>::fields_types = {{
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::B>::storage_names = {{
  "__fbthrift_field_a",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::B>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::A>::fields_names = {{
}};
THRIFT_DATA_SECTION const std::array<int16_t, 0> TStructDataStorage<::facebook::thrift::test::A>::fields_ids = {{
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 0> TStructDataStorage<::facebook::thrift::test::A>::fields_types = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::A>::storage_names = {{
}};
THRIFT_DATA_SECTION const std::array<int, 0> TStructDataStorage<::facebook::thrift::test::A>::isset_indexes = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::Config>::fields_names = {{
  "path",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::Config>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::Config>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::Config>::storage_names = {{
  "__fbthrift_field_path",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::Config>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::facebook::thrift::test::MyStruct>::fields_names = {{
  "field",
  "set_string",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 2> TStructDataStorage<::facebook::thrift::test::MyStruct>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 2> TStructDataStorage<::facebook::thrift::test::MyStruct>::fields_types = {{
  TType::T_I32,
  TType::T_SET,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::facebook::thrift::test::MyStruct>::storage_names = {{
  "__fbthrift_field_field",
  "__fbthrift_field_set_string",
}};
THRIFT_DATA_SECTION const std::array<int, 2> TStructDataStorage<::facebook::thrift::test::MyStruct>::isset_indexes = {{
  0,
  1,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 10> TStructDataStorage<::facebook::thrift::test::AdaptTestStruct>::fields_names = {{
  "delay",
  "custom",
  "timeout",
  "data",
  "meta",
  "indirectionString",
  "string_data",
  "double_wrapped_bool",
  "double_wrapped_integer",
  "binary_data",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 10> TStructDataStorage<::facebook::thrift::test::AdaptTestStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 10> TStructDataStorage<::facebook::thrift::test::AdaptTestStruct>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
  TType::T_I64,
  TType::T_I64,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_BOOL,
  TType::T_I32,
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 10> TStructDataStorage<::facebook::thrift::test::AdaptTestStruct>::storage_names = {{
  "__fbthrift_field_delay",
  "__fbthrift_field_custom",
  "__fbthrift_field_timeout",
  "__fbthrift_field_data",
  "__fbthrift_field_meta",
  "__fbthrift_field_indirectionString",
  "__fbthrift_field_string_data",
  "__fbthrift_field_double_wrapped_bool",
  "__fbthrift_field_double_wrapped_integer",
  "__fbthrift_field_binary_data",
}};
THRIFT_DATA_SECTION const std::array<int, 10> TStructDataStorage<::facebook::thrift::test::AdaptTestStruct>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 22> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedTestStruct>::fields_names = {{
  "adaptedBool",
  "adaptedByte",
  "adaptedShort",
  "adaptedInteger",
  "adaptedLong",
  "adaptedDouble",
  "adaptedString",
  "adaptedList",
  "adaptedSet",
  "adaptedMap",
  "adaptedBoolDefault",
  "adaptedByteDefault",
  "adaptedShortDefault",
  "adaptedIntegerDefault",
  "adaptedLongDefault",
  "adaptedDoubleDefault",
  "adaptedStringDefault",
  "adaptedEnum",
  "adaptedListDefault",
  "adaptedSetDefault",
  "adaptedMapDefault",
  "doubleTypedefBool",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 22> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedTestStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 22> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedTestStruct>::fields_types = {{
  TType::T_BOOL,
  TType::T_BYTE,
  TType::T_I16,
  TType::T_I32,
  TType::T_I64,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_LIST,
  TType::T_SET,
  TType::T_MAP,
  TType::T_BOOL,
  TType::T_BYTE,
  TType::T_I16,
  TType::T_I32,
  TType::T_I64,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_I32,
  TType::T_LIST,
  TType::T_SET,
  TType::T_MAP,
  TType::T_BOOL,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 22> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedTestStruct>::storage_names = {{
  "__fbthrift_field_adaptedBool",
  "__fbthrift_field_adaptedByte",
  "__fbthrift_field_adaptedShort",
  "__fbthrift_field_adaptedInteger",
  "__fbthrift_field_adaptedLong",
  "__fbthrift_field_adaptedDouble",
  "__fbthrift_field_adaptedString",
  "__fbthrift_field_adaptedList",
  "__fbthrift_field_adaptedSet",
  "__fbthrift_field_adaptedMap",
  "__fbthrift_field_adaptedBoolDefault",
  "__fbthrift_field_adaptedByteDefault",
  "__fbthrift_field_adaptedShortDefault",
  "__fbthrift_field_adaptedIntegerDefault",
  "__fbthrift_field_adaptedLongDefault",
  "__fbthrift_field_adaptedDoubleDefault",
  "__fbthrift_field_adaptedStringDefault",
  "__fbthrift_field_adaptedEnum",
  "__fbthrift_field_adaptedListDefault",
  "__fbthrift_field_adaptedSetDefault",
  "__fbthrift_field_adaptedMapDefault",
  "__fbthrift_field_doubleTypedefBool",
}};
THRIFT_DATA_SECTION const std::array<int, 22> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedTestStruct>::isset_indexes = {{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedNestedTestStruct>::fields_names = {{
  "adaptedStruct",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedNestedTestStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedNestedTestStruct>::fields_types = {{
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedNestedTestStruct>::storage_names = {{
  "__fbthrift_field_adaptedStruct",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::AdaptTemplatedNestedTestStruct>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion>::fields_names = {{
  "delay",
  "custom",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 2> TStructDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion>::fields_ids = {{
  1,
  2,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 2> TStructDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion>::fields_types = {{
  TType::T_I64,
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 2> TStructDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion>::storage_names = {{
  "delay",
  "custom",
}};
THRIFT_DATA_SECTION const std::array<int, 2> TStructDataStorage<::facebook::thrift::test::ThriftAdaptTestUnion>::isset_indexes = {{
  0,
  1,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::ThriftAdaptedStruct>::fields_names = {{
  "data",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::ThriftAdaptedStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::ThriftAdaptedStruct>::fields_types = {{
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::ThriftAdaptedStruct>::storage_names = {{
  "__fbthrift_field_data",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::ThriftAdaptedStruct>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdaptedStruct>::fields_names = {{
  "data",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdaptedStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdaptedStruct>::fields_types = {{
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdaptedStruct>::storage_names = {{
  "__fbthrift_field_data",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::detail::DirectlyAdaptedStruct>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 4> TStructDataStorage<::facebook::thrift::test::StructFieldAdaptedStruct>::fields_names = {{
  "adaptedStruct",
  "adaptedTypedef",
  "directlyAdapted",
  "typedefOfAdapted",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 4> TStructDataStorage<::facebook::thrift::test::StructFieldAdaptedStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 4> TStructDataStorage<::facebook::thrift::test::StructFieldAdaptedStruct>::fields_types = {{
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 4> TStructDataStorage<::facebook::thrift::test::StructFieldAdaptedStruct>::storage_names = {{
  "__fbthrift_field_adaptedStruct",
  "__fbthrift_field_adaptedTypedef",
  "__fbthrift_field_directlyAdapted",
  "__fbthrift_field_typedefOfAdapted",
}};
THRIFT_DATA_SECTION const std::array<int, 4> TStructDataStorage<::facebook::thrift::test::StructFieldAdaptedStruct>::isset_indexes = {{
  0,
  1,
  2,
  3,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::CircularAdaptee>::fields_names = {{
  "field",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::CircularAdaptee>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::CircularAdaptee>::fields_types = {{
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::CircularAdaptee>::storage_names = {{
  "__fbthrift_field_field",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::CircularAdaptee>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::CircularStruct>::fields_names = {{
  "field",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::CircularStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::CircularStruct>::fields_types = {{
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::CircularStruct>::storage_names = {{
  "__fbthrift_field_field",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::CircularStruct>::isset_indexes = {{
  -1,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingRenamedStruct>::fields_names = {{
  "data",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingRenamedStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingRenamedStruct>::fields_types = {{
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingRenamedStruct>::storage_names = {{
  "__fbthrift_field_data",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingRenamedStruct>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingSameNamespaceStruct>::fields_names = {{
  "data",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingSameNamespaceStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingSameNamespaceStruct>::fields_types = {{
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingSameNamespaceStruct>::storage_names = {{
  "__fbthrift_field_data",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::UnderlyingSameNamespaceStruct>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::detail::HeapAllocated>::fields_names = {{
}};
THRIFT_DATA_SECTION const std::array<int16_t, 0> TStructDataStorage<::facebook::thrift::test::detail::HeapAllocated>::fields_ids = {{
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 0> TStructDataStorage<::facebook::thrift::test::detail::HeapAllocated>::fields_types = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::detail::HeapAllocated>::storage_names = {{
}};
THRIFT_DATA_SECTION const std::array<int, 0> TStructDataStorage<::facebook::thrift::test::detail::HeapAllocated>::isset_indexes = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::MoveOnly>::fields_names = {{
  "ptr",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::MoveOnly>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::MoveOnly>::fields_types = {{
  TType::T_STRUCT,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::MoveOnly>::storage_names = {{
  "__fbthrift_field_ptr",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::MoveOnly>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::AlsoMoveOnly>::fields_names = {{
  "ptr",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::AlsoMoveOnly>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::AlsoMoveOnly>::fields_types = {{
  TType::T_I64,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::AlsoMoveOnly>::storage_names = {{
  "__fbthrift_field_ptr",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::AlsoMoveOnly>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::ApplyAdapter>::fields_names = {{
}};
THRIFT_DATA_SECTION const std::array<int16_t, 0> TStructDataStorage<::facebook::thrift::test::ApplyAdapter>::fields_ids = {{
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 0> TStructDataStorage<::facebook::thrift::test::ApplyAdapter>::fields_types = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::ApplyAdapter>::storage_names = {{
}};
THRIFT_DATA_SECTION const std::array<int, 0> TStructDataStorage<::facebook::thrift::test::ApplyAdapter>::isset_indexes = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::detail::TransitiveAdapted>::fields_names = {{
}};
THRIFT_DATA_SECTION const std::array<int16_t, 0> TStructDataStorage<::facebook::thrift::test::detail::TransitiveAdapted>::fields_ids = {{
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 0> TStructDataStorage<::facebook::thrift::test::detail::TransitiveAdapted>::fields_types = {{
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 0> TStructDataStorage<::facebook::thrift::test::detail::TransitiveAdapted>::storage_names = {{
}};
THRIFT_DATA_SECTION const std::array<int, 0> TStructDataStorage<::facebook::thrift::test::detail::TransitiveAdapted>::isset_indexes = {{
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 3> TStructDataStorage<::facebook::thrift::test::CountingStruct>::fields_names = {{
  "regularInt",
  "countingInt",
  "regularString",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 3> TStructDataStorage<::facebook::thrift::test::CountingStruct>::fields_ids = {{
  1,
  2,
  3,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 3> TStructDataStorage<::facebook::thrift::test::CountingStruct>::fields_types = {{
  TType::T_I64,
  TType::T_I64,
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 3> TStructDataStorage<::facebook::thrift::test::CountingStruct>::storage_names = {{
  "__fbthrift_field_regularInt",
  "__fbthrift_field_countingInt",
  "__fbthrift_field_regularString",
}};
THRIFT_DATA_SECTION const std::array<int, 3> TStructDataStorage<::facebook::thrift::test::CountingStruct>::isset_indexes = {{
  0,
  1,
  2,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::Person>::fields_names = {{
  "name",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::Person>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::Person>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::Person>::storage_names = {{
  "__fbthrift_field_name",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::Person>::isset_indexes = {{
  0,
}};

THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::Person2>::fields_names = {{
  "name",
}};
THRIFT_DATA_SECTION const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::test::Person2>::fields_ids = {{
  1,
}};
THRIFT_DATA_SECTION const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::test::Person2>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_SECTION const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::test::Person2>::storage_names = {{
  "__fbthrift_field_name",
}};
THRIFT_DATA_SECTION const std::array<int, 1> TStructDataStorage<::facebook::thrift::test::Person2>::isset_indexes = {{
  0,
}};

} // namespace thrift
} // namespace apache
