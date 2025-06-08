// Copyright 2011-2025 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "third_party/zynamics/binexport/util/status_macros.h"

#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "third_party/absl/memory/memory.h"
#include "third_party/absl/status/status.h"
#include "third_party/absl/status/status_matchers.h"
#include "third_party/absl/status/statusor.h"
#include "third_party/absl/strings/str_cat.h"

namespace not_absl {
namespace {

using ::absl_testing::StatusIs;

TEST(ReturnIfError, ReturnsOnErrorStatus) {
  auto func = []() -> absl::Status {
    NA_RETURN_IF_ERROR(absl::OkStatus());
    NA_RETURN_IF_ERROR(absl::OkStatus());
    NA_RETURN_IF_ERROR(absl::UnknownError("EXPECTED"));
    return absl::UnknownError("ERROR");
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

TEST(ReturnIfError, ReturnsOnErrorFromLambda) {
  auto func = []() -> absl::Status {
    NA_RETURN_IF_ERROR([] { return absl::OkStatus(); }());
    NA_RETURN_IF_ERROR([] { return absl::UnknownError("EXPECTED"); }());
    return absl::UnknownError("ERROR");
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

TEST(AssignOrReturn, AssignsMultipleVariablesInSequence) {
  auto func = []() -> absl::Status {
    int value1;
    NA_ASSIGN_OR_RETURN(value1, absl::StatusOr<int>(1));
    EXPECT_EQ(1, value1);
    int value2;
    NA_ASSIGN_OR_RETURN(value2, absl::StatusOr<int>(2));
    EXPECT_EQ(2, value2);
    int value3;
    NA_ASSIGN_OR_RETURN(value3, absl::StatusOr<int>(3));
    EXPECT_EQ(3, value3);
    int value4;
    NA_ASSIGN_OR_RETURN(value4,
                        absl::StatusOr<int>(absl::UnknownError("EXPECTED")));
    return absl::UnknownError(absl::StrCat("ERROR: assigned value ", value4));
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

TEST(AssignOrReturn, AssignsRepeatedlyToSingleVariable) {
  auto func = []() -> absl::Status {
    int value = 1;
    NA_ASSIGN_OR_RETURN(value, absl::StatusOr<int>(2));
    EXPECT_EQ(2, value);
    NA_ASSIGN_OR_RETURN(value, absl::StatusOr<int>(3));
    EXPECT_EQ(3, value);
    NA_ASSIGN_OR_RETURN(value, absl::StatusOr<int>(absl::StatusOr<int>(
                                   absl::UnknownError("EXPECTED"))));
    return absl::UnknownError("ERROR");
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

TEST(AssignOrReturn, MovesUniquePtr) {
  auto func = []() -> absl::Status {
    std::unique_ptr<int> ptr;
    NA_ASSIGN_OR_RETURN(
        ptr, absl::StatusOr<std::unique_ptr<int>>(absl::make_unique<int>(1)));
    EXPECT_EQ(*ptr, 1);
    return absl::UnknownError("EXPECTED");
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

TEST(AssignOrReturn, DoesNotAssignUniquePtrOnErrorStatus) {
  auto func = []() -> absl::Status {
    std::unique_ptr<int> ptr;
    NA_ASSIGN_OR_RETURN(ptr, absl::StatusOr<std::unique_ptr<int>>(
                                 absl::UnknownError("EXPECTED")));
    EXPECT_EQ(ptr, nullptr);
    return absl::OkStatus();
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

TEST(AssignOrReturn, MovesUniquePtrRepeatedlyToSingleVariable) {
  auto func = []() -> absl::Status {
    std::unique_ptr<int> ptr;
    NA_ASSIGN_OR_RETURN(
        ptr, absl::StatusOr<std::unique_ptr<int>>(absl::make_unique<int>(1)));
    EXPECT_EQ(*ptr, 1);
    NA_ASSIGN_OR_RETURN(
        ptr, absl::StatusOr<std::unique_ptr<int>>(absl::make_unique<int>(2)));
    EXPECT_EQ(*ptr, 2);
    return absl::UnknownError("EXPECTED");
  };

  EXPECT_THAT(func(), StatusIs(absl::StatusCode::kUnknown, "EXPECTED"));
}

}  // namespace
}  // namespace not_absl
