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

#ifndef WRITER_H_
#define WRITER_H_

#include "third_party/absl/status/status.h"
#include "third_party/zynamics/binexport/address_references.h"
#include "third_party/zynamics/binexport/comment.h"
#include "third_party/zynamics/binexport/instruction.h"

class CallGraph;
class FlowGraph;

namespace security::binexport {

class Writer {
 public:
  Writer() = default;

  Writer(const Writer&) = delete;
  const Writer& operator=(const Writer&) = delete;

  virtual ~Writer() = default;

  virtual absl::Status Write(const CallGraph& call_graph,
                             const FlowGraph& flow_graph,
                             const detego::Instructions& instructions,
                             const AddressReferences& address_references,
                             const AddressSpace& address_space) = 0;
};

}  // namespace security::binexport

#endif  // WRITER_H_
