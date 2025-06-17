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

#include "third_party/zynamics/binexport/dump_writer.h"

#include <algorithm>
#include <iomanip>
#include <limits>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "third_party/absl/status/status.h"
#include "third_party/zynamics/binexport/address_references.h"
#include "third_party/zynamics/binexport/call_graph.h"
#include "third_party/zynamics/binexport/flow_graph.h"
#include "third_party/zynamics/binexport/instruction.h"
#include "third_party/zynamics/binexport/util/format.h"
#include "third_party/zynamics/binexport/util/types.h"
#include "third_party/zynamics/binexport/virtual_memory.h"

namespace security::binexport {

DumpWriter::DumpWriter(std::ostream& stream) : stream_(stream) {}

DumpWriter::DumpWriter(const std::string& file_name)
    : file_(file_name.c_str()), stream_(file_) {}

absl::Status DumpWriter::Write(const CallGraph& call_graph,
                               const FlowGraph& flow_graph, const Instructions&,
                               const AddressReferences&, const AddressSpace&) {
  // Store to an array and sort by MD index value for compatibility.
  const auto& functions = flow_graph.GetFunctions();
  std::vector<std::pair<double, Address>> md_indices;
  md_indices.reserve(functions.size());
  for (const auto& function : functions) {
    md_indices.emplace_back(function.second->GetMdIndex(), function.first);
  }
  std::sort(md_indices.begin(), md_indices.end(),
            [](const std::pair<double, Address>& p1,
               const std::pair<double, Address>& p2) {
              // Sort by MD index descending, then address ascending.
              return p1.first != p2.first ? p1.first > p2.first
                                          : p1.second < p2.second;
            });

  for (const auto& [md_index, address] : md_indices) {
    stream_ << FormatAddress(address) << "\t"
            << std::setprecision(std::numeric_limits<double>::max_digits10)
            << std::setfill(' ') << std::setw(24) << md_index << "\n";
  }

  stream_ << std::endl;
  call_graph.Render(&stream_, flow_graph);
  stream_ << std::endl;
  flow_graph.Render(&stream_, call_graph);
  stream_ << std::endl;
  return absl::OkStatus();
}

}  // namespace security::binexport
