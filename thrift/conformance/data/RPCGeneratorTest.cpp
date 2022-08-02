/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
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

#include <thrift/conformance/data/RPCGenerator.h>

#include <folly/portability/GTest.h>

namespace apache::thrift::conformance::data {

TEST(TestGeneratorTest, RoundTripSuite) {
  auto suite = createRPCTestSuite();
  EXPECT_EQ(suite.name(), "ThriftRPCTest");
  EXPECT_EQ(suite.tests()->size(), 1);
  const auto& test = suite.tests()->at(0);
  EXPECT_EQ(test.name(), "RequestResponseBasicTest");
  const auto& testCase = test.testCases()->at(0);
  EXPECT_EQ(testCase.name(), "RequestResponse/Success");
  EXPECT_TRUE(testCase.test()->requestResponse_ref());
}

} // namespace apache::thrift::conformance::data
