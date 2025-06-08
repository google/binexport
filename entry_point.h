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

#ifndef ENTRY_POINT_H_
#define ENTRY_POINT_H_

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "third_party/zynamics/binexport/instruction.h"
#include "third_party/zynamics/binexport/util/types.h"
#include "third_party/zynamics/binexport/virtual_memory.h"

class EntryPoint {
 public:
  // Possible sources for entry points.
  enum class Source {
    CODE_FLOW = 0,
    CALL_TARGET,
    JUMP_ANY,
    JUMP_DIRECT,
    JUMP_INDIRECT,
    JUMP_TABLE,
    JUMP_TABLE_BACKWARDS,
    ADDRESS_TABLE,
    RUNTIME_CALL_TARGET,
    FUNCTION_SIGNATURE,
    FUNCTION_PROLOGUE,
    FUNCTION_PROLOGUE_MODEL,
    FUNCTION_CHUNK,
    ENTRY_POINT_IMAGE,  // Process memory image
    ENTRY_POINT_FILE,   // Entry point text file
    PE64_EXCEPTION_INFO,
    MSIL_EXCEPTION_RECORD,
    GOLANG_TYPE_INFO,
  };

  static constexpr int kFlagsNone = 0;
  // Used to indicate that the disassembler should probe for the code type
  // (where this is appropriate to do so i.e. ARM, otherwise ignore it).
  static constexpr int kFlagsProbeCodeType = 1 << 0;

  EntryPoint(Address address, EntryPoint::Source source,
             const int flags = kFlagsNone);

  std::string SourceToString() const;

  bool IsFunctionPrologue() const {
    return source_ == Source::FUNCTION_PROLOGUE ||
           source_ == Source::FUNCTION_SIGNATURE ||
           source_ == Source::FUNCTION_PROLOGUE_MODEL;
  }
  bool IsCallTarget() const {
    return source_ == Source::CALL_TARGET ||
           source_ == Source::RUNTIME_CALL_TARGET;
  }
  bool IsExternal() const {
    return source_ == Source::ENTRY_POINT_IMAGE ||
           source_ == Source::ENTRY_POINT_FILE;
  }

  Address address_;
  EntryPoint::Source source_;
  int flags_;
};

bool operator<(const EntryPoint& lhs, const EntryPoint& rhs);
bool operator==(const EntryPoint& lhs, const EntryPoint& rhs);

using EntryPoints = std::vector<EntryPoint>;

// EntryPointManager is not thread safe.
class EntryPointManager {
 public:
  EntryPointManager(EntryPointManager* parent, std::string name)
      : parent_(parent),
        entry_points_(parent->entry_points_),
        count_(0),
        name_(std::move(name)),
        memory_flags_(nullptr) {}
  EntryPointManager(EntryPoints* entry_points, std::string name)
      : EntryPointManager(entry_points, std::move(name),
                          /*memory_flags=*/nullptr) {}
  EntryPointManager(EntryPoints* entry_points, std::string name,
                    AddressSpace* memory_flags)
      : parent_(nullptr),
        entry_points_(entry_points),
        count_(0),
        name_(std::move(name)),
        memory_flags_(memory_flags) {}

  ~EntryPointManager();

  void Add(Address address, EntryPoint::Source source,
           const int flags = EntryPoint::kFlagsNone);

  EntryPoints* entry_points() { return entry_points_; }

  bool IsEntryPoint(Address address) const {
    return memory_flags_ != nullptr && memory_flags_->IsValidAddress(address) &&
           (memory_flags_->GetFlags(address) & FLAG_ENTRY_POINT);
  }

  bool IsPotentialEntryPoint(Address address) const {
    return std::find_if(entry_points_->cbegin(), entry_points_->cend(),
                        [address](const EntryPoint& check) {
                          return (check.address_ == address) &&
                                 (check.IsCallTarget() || check.IsExternal() ||
                                  check.IsFunctionPrologue());
                        }) != entry_points_->cend();
  }

 private:
  EntryPointManager* parent_;
  EntryPoints* entry_points_;
  size_t count_;
  const std::string name_;
  const AddressSpace* memory_flags_;  // Not owned.
};

#endif  // ENTRY_POINT_H_
