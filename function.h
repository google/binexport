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

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

#include "third_party/absl/container/btree_map.h"
#include "third_party/absl/container/node_hash_set.h"
#include "third_party/absl/log/check.h"
#include "third_party/zynamics/binexport/basic_block.h"
#include "third_party/zynamics/binexport/edge.h"
#include "third_party/zynamics/binexport/util/types.h"

class CallGraph;
class Function;
class FlowGraph;

using Functions = absl::btree_map<Address, Function*>;

class Function {
 public:
  using Edges = std::vector<FlowGraphEdge>;

  enum FunctionType : uint8_t {
    TYPE_NONE = 123,
    TYPE_STANDARD = 0,
    TYPE_LIBRARY = 1,
    TYPE_IMPORTED = 2,
    TYPE_THUNK = 3,
    TYPE_INVALID = 4,
  };

  enum Name {
    MANGLED = 0,
    DEMANGLED = 1,
  };

  static const char* GetTypeName(FunctionType type);

  explicit Function(Address entry_point);

  Function(const Function&) = delete;
  Function& operator=(const Function&) = delete;

  ~Function();

  // Deletes basic blocks and edges, but leaves entry point and name intact.
  void Clear();

  void AddBasicBlock(BasicBlock* basic_block);
  void AddEdge(const FlowGraphEdge& edge);
  void SortGraph();
  void FixEdges();

  // Returns the set of loop edges as determined by the Dominator Tree algorithm
  // by Lengauer and Tarjan. Edges will be returned sorted by source address,
  // which is the same order they are stored in the graph itself.
  void GetBackEdges(std::vector<Edges::const_iterator>* back_edges) const;

  Address GetEntryPoint() const;

  void SetType(FunctionType value) { type_ = value; }
  FunctionType GetType() const { return type_; }

  // Returns the function type. If the function has not been assigned any type,
  // extra heuristics are applied; returning TYPE_THUNK for functions with entry
  // point address 0, THUNK_IMPORTED if it has no basic blocks and
  // TYPE_STANDARD otherwise.
  FunctionType GetTypeHeuristic() const;

  bool IsImported() const;

  std::string GetModuleName() const;
  void SetModuleName(const std::string& name);
  void SetName(const std::string& name, const std::string& demangled_name);
  std::string GetName(Name type) const;
  bool HasRealName() const;

  const Edges& GetEdges() const { return edges_; }
  const BasicBlocks& GetBasicBlocks() const { return basic_blocks_; }
  const BasicBlock* GetBasicBlockForAddress(Address address) const;

  void Render(std::ostream* stream, const CallGraph& call_graph,
              const FlowGraph& flow_graph) const;

  int GetLibraryIndex() const { return library_index_; }
  void SetLibraryIndex(int value) { library_index_ = value; }

  double GetMdIndex() const { return md_index_; }
  void SetMdIndex(double value) { md_index_ = value; }

 private:
  int GetBasicBlockIndexForAddress(Address address) const;
  BasicBlock* GetMutableBasicBlockForAddress(Address address);

  using StringCache = absl::node_hash_set<std::string>;
  static thread_local StringCache string_cache_;
  static thread_local int instance_count_;

  Address entry_point_;
  BasicBlocks basic_blocks_;
  Edges edges_;
  std::string name_;
  std::string demangled_name_;
  const std::string* module_name_ = nullptr;
  FunctionType type_ = TYPE_NONE;
  int library_index_ = -1;
  double md_index_;
};

#endif  // FUNCTION_H_
