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

#include "third_party/zynamics/binexport/util/filesystem.h"

#include <fstream>
#include <iostream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "third_party/absl/status/status_matchers.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/zynamics/binexport/util/status_macros.h"

namespace security::binexport {
namespace {

using ::absl_testing::IsOk;
using ::testing::IsEmpty;
using ::testing::IsFalse;
using ::testing::IsTrue;
using ::testing::StrEq;

TEST(FileSystemTest, Basename) {
  EXPECT_THAT(Basename(absl::StrCat(kPathSeparator, "subdir", kPathSeparator,
                                    "filename.ext")),
              StrEq("filename.ext"));
#ifdef _WIN32
  EXPECT_THAT(Basename(R"(C:\subdir/with\mixed_separators\filename.ext)"),
              StrEq("filename.ext"));
  EXPECT_THAT(Basename(R"(C:\subdir/with\mixed_separators/filename.ext)"),
              StrEq("filename.ext"));
#endif
  EXPECT_THAT(Basename(absl::StrCat("unicode", kPathSeparator, "官话",
                                    kPathSeparator, "filename.ext")),
              StrEq("filename.ext"));
}

TEST(FileSystemTest, Dirname) {
  EXPECT_THAT(Dirname(absl::StrCat("subdir1", kPathSeparator, "subdir2",
                                   kPathSeparator, "filename.ext")),
              StrEq(absl::StrCat("subdir1", kPathSeparator, "subdir2")));

  EXPECT_THAT(Dirname(absl::StrCat("unicode", kPathSeparator, "官话",
                                   kPathSeparator, "filename.ext")),
              StrEq(absl::StrCat("unicode", kPathSeparator, "官话")));
}

TEST(FileSystemTest, Extensions) {
  EXPECT_THAT(
      GetFileExtension(absl::StrCat("subdir", kPathSeparator, "filename.ext")),
      StrEq(".ext"));
  EXPECT_THAT(GetFileExtension("filename_noext"), IsEmpty());

  EXPECT_THAT(
      ReplaceFileExtension(
          absl::StrCat("subdir", kPathSeparator, "filename.ext"), ".new"),
      StrEq(absl::StrCat("subdir", kPathSeparator, "filename.new")));
  EXPECT_THAT(
      ReplaceFileExtension(
          absl::StrCat("subdir", kPathSeparator, "filename_noext"), ".new"),
      StrEq(absl::StrCat("subdir", kPathSeparator, "filename_noext.new")));
  // Remove file extension
  EXPECT_THAT(ReplaceFileExtension(
                  absl::StrCat("subdir", kPathSeparator, "filename.ext"), ""),
              StrEq(absl::StrCat("subdir", kPathSeparator, "filename")));
  // Test that directories with a "." in them don't throw off the extension
  // replacement.
  EXPECT_THAT(
      ReplaceFileExtension(
          absl::StrCat("sub.dir", kPathSeparator, "filename_noext"), ".new"),
      StrEq(absl::StrCat("sub.dir", kPathSeparator, "filename_noext.new")));
}

TEST(FileSystemTest, JoinPaths) {
  EXPECT_THAT(JoinPath("a", "b"),
              StrEq(absl::StrCat("a", kPathSeparator, "b")));
#ifndef _WIN32
  EXPECT_THAT(JoinPath("/a", "b"), StrEq("/a/b"));
#endif
}

TEST(FileSystemTest, FullPaths) {
  const std::string current = GetCurrentDirectory();
  EXPECT_THAT(GetFullPathName("filename"),
              StrEq(absl::StrCat(current, kPathSeparator, "filename")));
}

TEST(FileSystemTest, CreateAndRemoveDirectories) {
  NA_ASSERT_OK_AND_ASSIGN(std::string temp_dir,
                          GetOrCreateTempDirectory("test"));

  const std::string test_path = JoinPath(temp_dir, "sub", "dir", "s2");
  EXPECT_THAT(CreateDirectories(test_path), IsOk());

  EXPECT_THAT(RemoveAll(test_path), IsOk());
  EXPECT_THAT(IsDirectory(test_path), IsFalse());
}

TEST(FileSystemTest, LinkingFiles) {
  NA_ASSERT_OK_AND_ASSIGN(std::string temp_dir,
                          GetOrCreateTempDirectory("test"));
  const std::string target = JoinPath(temp_dir, "target");
  const std::string link_path = JoinPath(temp_dir, "link");
  {
    std::ofstream out(target, std::ios::trunc);
    out << "test_content";
    ASSERT_THAT(out.good(), IsTrue());
  }

  EXPECT_THAT(CreateOrUpdateLinkWithFallback(target, link_path), IsOk());
}

}  // namespace
}  // namespace security::binexport
