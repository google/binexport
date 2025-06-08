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

#ifndef IDA_METAPC_H_
#define IDA_METAPC_H_

#include "third_party/zynamics/binexport/call_graph.h"
#include "third_party/zynamics/binexport/flow_graph.h"
#include "third_party/zynamics/binexport/instruction.h"
#include "third_party/zynamics/binexport/util/types.h"

class insn_t;

namespace security::binexport {

Instruction ParseInstructionIdaMetaPc(const insn_t& instruction,
                                      CallGraph* call_graph,
                                      FlowGraph* flow_graph);

}  // namespace security::binexport

#endif  // IDA_METAPC_H_
