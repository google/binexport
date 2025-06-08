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

#include "third_party/zynamics/binexport/statistics_writer.h"

#include <iomanip>
#include <ios>
#include <ostream>
#include <string>

#include "third_party/absl/container/flat_hash_map.h"
#include "third_party/zynamics/binexport/call_graph.h"
#include "third_party/zynamics/binexport/flow_graph.h"

namespace security::binexport {

StatisticsWriter::StatisticsWriter(std::ostream& stream) : stream_(stream) {}

StatisticsWriter::StatisticsWriter(const std::string& filename)
    : file_(filename.c_str()), stream_(file_) {}

void StatisticsWriter::GenerateStatistics(
    const CallGraph& call_graph, const FlowGraph& flow_graph,
    absl::flat_hash_map<std::string, size_t>* statistics_ptr) const {
  absl::flat_hash_map<std::string, size_t>& statistics = *statistics_ptr;
  statistics.clear();
  const Functions& functions = flow_graph.GetFunctions();
  statistics["callgraph nodes (functions)"] = functions.size();
  statistics["callgraph edges (calls)"] = call_graph.GetEdges().size();

  static const char* kFunctionTypeNames[] = {
      "functions (standard)", "functions (library)", "functions (imported)",
      "functions (thunk)", "functions (invalid)"};
  statistics[kFunctionTypeNames[0]] = 0;
  statistics[kFunctionTypeNames[1]] = 0;
  statistics[kFunctionTypeNames[2]] = 0;
  statistics[kFunctionTypeNames[3]] = 0;
  statistics[kFunctionTypeNames[4]] = 0;

  static const char* kEdgeTypeNames[] = {
      "flowgraph edges (true)", "flowgraph edges (false)",
      "flowgraph edges (unconditional)", "flowgraph edges (switch)"};
  statistics[kEdgeTypeNames[0]] = 0;
  statistics[kEdgeTypeNames[1]] = 0;
  statistics[kEdgeTypeNames[2]] = 0;
  statistics[kEdgeTypeNames[3]] = 0;

  statistics["functions with real name"] = 0;
  statistics["instructions"] = 0;

  size_t basic_block_count = 0;
  size_t edge_count = 0;
  for (Functions::const_iterator i = functions.begin(); i != functions.end();
       ++i) {
    const Function& function = *i->second;
    assert(function.GetTypeHeuristic() != Function::TYPE_NONE);
    statistics[kFunctionTypeNames[function.GetTypeHeuristic()]]++;
    statistics["functions with real name"] += function.HasRealName();

    const auto& basic_blocks = function.GetBasicBlocks();
    const auto& edges = function.GetEdges();
    basic_block_count += basic_blocks.size();
    edge_count += edges.size();

    for (const auto k : basic_blocks) {
      const BasicBlock& basic_block = *k;
      statistics["instructions"] += basic_block.GetInstructionCount();
      for (const auto& instruction : basic_block) {
        statistics["instructions " + instruction.GetMnemonic()]++;
      }
    }

    for (Function::Edges::const_iterator j = edges.begin(); j != edges.end();
         ++j) {
      const FlowGraphEdge& edge = *j;
      assert(edge.type > 0 && edge.type < 5);
      statistics[kEdgeTypeNames[edge.type - 1]]++;
    }
  }

  statistics["flowgraph nodes (basicblocks)"] = basic_block_count;
  statistics["flowgraph edges"] = edge_count;
}

absl::Status StatisticsWriter::Write(const CallGraph& call_graph,
                                     const FlowGraph& flow_graph,
                                     const Instructions&,
                                     const AddressReferences&,
                                     const AddressSpace&) {
  absl::flat_hash_map<std::string, size_t> statistics;
  GenerateStatistics(call_graph, flow_graph, &statistics);
  for (const auto& entry : statistics) {
    const std::string padding(32 - entry.first.size(), '.');
    stream_ << entry.first << padding << ":" << std::setw(7) << std::dec
            << std::setfill(' ') << entry.second << std::endl;
  }

  return absl::OkStatus();
}

}  // namespace security::binexport
