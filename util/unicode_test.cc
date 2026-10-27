// Copyright 2011-2026 Google LLC
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

#include "third_party/zynamics/binexport/util/unicode.h"

#include <cstddef>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "third_party/absl/strings/match.h"
#include "third_party/absl/strings/str_cat.h"
#include "third_party/absl/strings/string_view.h"

namespace security::binexport {
namespace {

using ::testing::Eq;
using ::testing::IsEmpty;

// Builds a string_view from a byte literal that may contain NUL bytes.
template <size_t N>
absl::string_view Bytes(const char (&bytes)[N]) {
  return absl::string_view(bytes, N - 1);
}

constexpr absl::string_view kReplacement = "\xEF\xBF\xBD";  // U+FFFD

// All bytes that ReplaceNonPrintableAscii() keeps.
constexpr absl::string_view kPrintable =
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`"
    "abcdefghijklmnopqrstuvwxyz{|}~\t\n\f\r";

TEST(Utf16LeToUtf8Test, Empty) { EXPECT_THAT(Utf16LeToUtf8(""), IsEmpty()); }

TEST(Utf16LeToUtf8Test, Ascii) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("H\0i\0!\0")), Eq("Hi!"));
}

TEST(Utf16LeToUtf8Test, TwoAndThreeByteSequences) {
  // U+00E9 LATIN SMALL LETTER E WITH ACUTE, U+4E2D CJK "middle".
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xE9\x00\x2D\x4E")),
              Eq("\xC3\xA9\xE4\xB8\xAD"));
}

TEST(Utf16LeToUtf8Test, EncodingBoundaries) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x7F\x00")), Eq("\x7F"));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x80\x00")), Eq("\xC2\x80"));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xFF\x07")), Eq("\xDF\xBF"));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\x08")), Eq("\xE0\xA0\x80"));
  // Last code points before and after the surrogate range.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xFF\xD7")), Eq("\xED\x9F\xBF"));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xE0")), Eq("\xEE\x80\x80"));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xFF\xFF")), Eq("\xEF\xBF\xBF"));
}

TEST(Utf16LeToUtf8Test, SurrogatePairs) {
  // U+1F600 GRINNING FACE.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x3D\xD8\x00\xDE")), Eq("\xF0\x9F\x98\x80"));
  // U+10000, the first supplementary code point.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xD8\x00\xDC")), Eq("\xF0\x90\x80\x80"));
  // U+10FFFF, the last code point.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xFF\xDB\xFF\xDF")), Eq("\xF4\x8F\xBF\xBF"));
}

TEST(Utf16LeToUtf8Test, SurrogatePairRangeCorners) {
  // Lowest high surrogate with highest low surrogate: U+103FF.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xD8\xFF\xDF")), Eq("\xF0\x90\x8F\xBF"));
  // Highest high surrogate with lowest low surrogate: U+10FC00.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xFF\xDB\x00\xDC")), Eq("\xF4\x8F\xB0\x80"));
  // U+24B62.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x52\xD8\x62\xDF")), Eq("\xF0\xA4\xAD\xA2"));
}

TEST(Utf16LeToUtf8Test, KeepsNul) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("a\0\0\0b\0")), Eq(Bytes("a\0b")));
}

TEST(Utf16LeToUtf8Test, ReplacesTrailingOddByte) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("a")), Eq(kReplacement));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("a\0b")),
              Eq(absl::StrCat("a", kReplacement)));
  // The odd byte must not be combined into a surrogate pair.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x3D\xD8\x00")),
              Eq(absl::StrCat(kReplacement, kReplacement)));
}

// Regression test for the SIGABRT in BinExport2Writer::WriteStrings(): strings
// with unpaired surrogates made std::wstring_convert throw std::range_error.
TEST(Utf16LeToUtf8Test, LoneHighSurrogateAtEnd) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("a\0\x3D\xD8")),
              Eq(absl::StrCat("a", kReplacement)));
}

TEST(Utf16LeToUtf8Test, LoneHighSurrogateFollowedByNonSurrogate) {
  // The unit after the lone high surrogate must not be swallowed.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x3D\xD8"
                                  "a\0")),
              Eq(absl::StrCat(kReplacement, "a")));
}

TEST(Utf16LeToUtf8Test, TwoLoneHighSurrogatesAtEnd) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xD8\x00\xD8")),
              Eq(absl::StrCat(kReplacement, kReplacement)));
}

TEST(Utf16LeToUtf8Test, LoneLowSurrogateThenOddByte) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xDC\x41")),
              Eq(absl::StrCat(kReplacement, kReplacement)));
}

TEST(Utf16LeToUtf8Test, LoneLowSurrogate) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xDC")), Eq(kReplacement));
  EXPECT_THAT(Utf16LeToUtf8(Bytes("a\0\xFF\xDF"
                                  "b\0")),
              Eq(absl::StrCat("a", kReplacement, "b")));
}

TEST(Utf16LeToUtf8Test, ReversedSurrogatePair) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x00\xDE\x3D\xD8")),
              Eq(absl::StrCat(kReplacement, kReplacement)));
}

TEST(Utf16LeToUtf8Test, TwoHighSurrogatesThenLow) {
  // The first high surrogate is unpaired, the second pairs with the low one.
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\x3D\xD8\x3D\xD8\x00\xDE")),
              Eq(absl::StrCat(kReplacement, "\xF0\x9F\x98\x80")));
}

TEST(Utf16LeToUtf8Test, ReplacementCharacterPassesThrough) {
  EXPECT_THAT(Utf16LeToUtf8(Bytes("\xFD\xFF")), Eq(kReplacement));
}

TEST(ReplaceNonPrintableAsciiTest, Empty) {
  EXPECT_THAT(ReplaceNonPrintableAscii(""), IsEmpty());
}

TEST(ReplaceNonPrintableAsciiTest, KeepsPrintableAndSomeWhitespace) {
  EXPECT_THAT(ReplaceNonPrintableAscii(kPrintable), Eq(kPrintable));
}

TEST(ReplaceNonPrintableAsciiTest, AllByteValues) {
  for (int byte = 0; byte < 256; ++byte) {
    const std::string input(1, static_cast<char>(byte));
    const bool keep = absl::StrContains(kPrintable, static_cast<char>(byte));
    EXPECT_THAT(ReplaceNonPrintableAscii(input), Eq(keep ? input : " "))
        << "byte: " << byte;
  }
}

TEST(ReplaceNonPrintableAsciiTest, HighBytesBecomeSpaces) {
  // Bytes >= 0x80 are negative where char is signed. They used to index a
  // lookup table out of bounds in such builds.
  EXPECT_THAT(ReplaceNonPrintableAscii(Bytes("a\x80\xFF\0\x0B"
                                             "b")),
              Eq("a    b"));
}

}  // namespace
}  // namespace security::binexport
