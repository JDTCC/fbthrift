#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import typing as _typing

import folly.iobuf as __iobuf
import thrift.py3.builder


import module.types as _module_types


class MyStruct_Builder(thrift.py3.builder.StructBuilder):
    major: _typing.Optional[int]
    package: _typing.Optional[str]
    annotation_with_quote: _typing.Optional[str]
    class_: _typing.Optional[str]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class SecretStruct_Builder(thrift.py3.builder.StructBuilder):
    id: _typing.Optional[int]
    password: _typing.Optional[str]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


