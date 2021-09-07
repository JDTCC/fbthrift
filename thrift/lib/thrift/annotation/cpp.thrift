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

// TODO(viz): Consider moving to a cpp-specific lib directory.

include "thrift/lib/thrift/annotation/scope.thrift"

namespace cpp2 thrift.lib.thrift.annotation
namespace py3 thrift.lib.thrift.annotation
namespace py thrift.lib.thrift.annotation.cpp
namespace java.swift org.apache.thrift.annotation

enum RefType {
  Unique = 0,
  Shared = 1,
  SharedMutable = 2,
}

@scope.Field
struct Ref {
  1: RefType type;
} (thrift.uri = "facebook.com/thrift/annotation/cpp/Ref")

@scope.Field
struct Lazy {
} (thrift.uri = "facebook.com/thrift/annotation/cpp/Lazy")

// An experimental annotation that applies a C++ adapter to fields. For example:
//
//   struct User {
//     @cpp.ExperimentalAdapter{name = "IdAdapter"}
//     1: i64 id;
//   }
//
// Here the field `id` has the C++ adapter `IdAdapter`.
@scope.Field
struct ExperimentalAdapter {
  // The name of a C++ adapter type used to convert between Thrift and native
  // C++ representation.
  1: string name;
} (thrift.uri = "facebook.com/thrift/annotation/ExperimentalAdapter")
