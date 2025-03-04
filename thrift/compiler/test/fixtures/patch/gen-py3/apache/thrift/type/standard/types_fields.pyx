#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cython.operator cimport dereference as deref
from libcpp.memory cimport make_unique, unique_ptr, shared_ptr
from thrift.py3.types cimport assign_unique_ptr, assign_shared_ptr, assign_shared_const_ptr

cimport thrift.py3.types
from thrift.py3.types cimport (
    reset_field as __reset_field,
    StructFieldsSetter as __StructFieldsSetter
)

from thrift.py3.types cimport const_pointer_cast


@__cython.auto_pickle(False)
cdef class __DurationStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __DurationStruct_FieldsSetter _fbthrift_create(_apache_thrift_type_standard_types.cDurationStruct* struct_cpp_obj):
        cdef __DurationStruct_FieldsSetter __fbthrift_inst = __DurationStruct_FieldsSetter.__new__(__DurationStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"seconds")] = __DurationStruct_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"nanos")] = __DurationStruct_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__DurationStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __DurationStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field seconds
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cDurationStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'seconds is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).seconds_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field nanos
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cDurationStruct](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'nanos is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).nanos_ref().assign(_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __TimeStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __TimeStruct_FieldsSetter _fbthrift_create(_apache_thrift_type_standard_types.cTimeStruct* struct_cpp_obj):
        cdef __TimeStruct_FieldsSetter __fbthrift_inst = __TimeStruct_FieldsSetter.__new__(__TimeStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"seconds")] = __TimeStruct_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"nanos")] = __TimeStruct_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__TimeStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __TimeStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field seconds
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cTimeStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'seconds is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).seconds_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field nanos
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cTimeStruct](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'nanos is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).nanos_ref().assign(_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __FractionStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __FractionStruct_FieldsSetter _fbthrift_create(_apache_thrift_type_standard_types.cFractionStruct* struct_cpp_obj):
        cdef __FractionStruct_FieldsSetter __fbthrift_inst = __FractionStruct_FieldsSetter.__new__(__FractionStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"numerator")] = __FractionStruct_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"denominator")] = __FractionStruct_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__FractionStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __FractionStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field numerator
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cFractionStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'numerator is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).numerator_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field denominator
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cFractionStruct](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'denominator is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).denominator_ref().assign(_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __UriStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __UriStruct_FieldsSetter _fbthrift_create(_apache_thrift_type_standard_types.cUriStruct* struct_cpp_obj):
        cdef __UriStruct_FieldsSetter __fbthrift_inst = __UriStruct_FieldsSetter.__new__(__UriStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"scheme")] = __UriStruct_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"domain")] = __UriStruct_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"path")] = __UriStruct_FieldsSetter._set_field_2
        __fbthrift_inst._setters[__cstring_view(<const char*>"query")] = __UriStruct_FieldsSetter._set_field_3
        __fbthrift_inst._setters[__cstring_view(<const char*>"fragment")] = __UriStruct_FieldsSetter._set_field_4
        return __fbthrift_inst

    cdef void set_field(__UriStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __UriStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field scheme
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cUriStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'scheme is not a { str !r}.')
        deref(self._struct_cpp_obj).scheme_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field domain
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cUriStruct](deref(self._struct_cpp_obj), 1)
            return
        deref(self._struct_cpp_obj).domain_ref().assign(deref(_apache_thrift_type_standard_types.List__string(_fbthrift_value)._cpp_obj))

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field path
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cUriStruct](deref(self._struct_cpp_obj), 2)
            return
        deref(self._struct_cpp_obj).path_ref().assign(deref(_apache_thrift_type_standard_types.List__string(_fbthrift_value)._cpp_obj))

    cdef void _set_field_3(self, _fbthrift_value) except *:
        # for field query
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cUriStruct](deref(self._struct_cpp_obj), 3)
            return
        deref(self._struct_cpp_obj).query_ref().assign(deref(_apache_thrift_type_standard_types.Map__string_string(_fbthrift_value)._cpp_obj))

    cdef void _set_field_4(self, _fbthrift_value) except *:
        # for field fragment
        if _fbthrift_value is None:
            __reset_field[_apache_thrift_type_standard_types.cUriStruct](deref(self._struct_cpp_obj), 4)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'fragment is not a { str !r}.')
        deref(self._struct_cpp_obj).fragment_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

