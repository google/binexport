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

#include "third_party/zynamics/binexport/call_graph.h"

#include <algorithm>
#include <iomanip>
#include <iterator>
#include <ostream>
#include <string>
#include <utility>

#include "third_party/zynamics/binexport/flow_graph.h"
#include "third_party/zynamics/binexport/util/format.h"
#include "third_party/zynamics/binexport/util/hash.h"

using security::binexport::FormatAddress;

namespace {

bool EdgeFunctionIsNull(const EdgeInfo& edge) { return edge.function_ == 0; }

bool AreDuplicateRegularComments(const Comment& lhs, const Comment& rhs) {
  return lhs.address == rhs.address && lhs.type == Comment::REGULAR &&
         rhs.type == Comment::REGULAR;
}

}  // namespace

thread_local CallGraph::StringCache CallGraph::string_cache_;
thread_local int CallGraph::instance_count_ = 0;

// Attention: do _not_ use source_basic_block_id for sorting!
// We change that after putting EdgeInfos in a set!
bool operator<(const EdgeInfo& one, const EdgeInfo& two) {
  if (one.source_ != two.source_) {
    return one.source_ < two.source_;
  }

  if (one.function_ != two.function_) {
    return one.function_->GetEntryPoint() < two.function_->GetEntryPoint();
  }

  return one.target_ < two.target_;
}

bool operator==(const EdgeInfo& one, const EdgeInfo& two) {
  return one.function_ == two.function_ && one.source_ == two.source_ &&
         one.target_ == two.target_;
}

void CallGraph::Render(std::ostream* stream,
                       const FlowGraph& flow_graph) const {
  for (const auto& function_address : functions_) {
    const Function* function = flow_graph.GetFunction(function_address);
    *stream << FormatAddress(function_address) << " " << std::setfill(' ')
            << std::setw(8)
            << (function->GetTypeHeuristic() != Function::TYPE_STANDARD
                    ? Function::GetTypeName(function->GetTypeHeuristic())
                    : "")
            << " " << function->GetModuleName()
            << (function->GetModuleName().empty() ? "" : ".")
            << function->GetName(Function::DEMANGLED);
    int library_index = function->GetLibraryIndex();
    if (library_index != -1) {
      const auto& library = library_manager_.GetKnownLibrary(library_index);
      *stream << " from " << (library.IsStatic() ? "static" : "dynamic")
              << " library " << library.name;
    }
    // Prefer "\n" over endl when calling it in a loop as std::endl flushes the
    // stream every time.
    *stream << "\n";
  }

  for (const auto& edge : edges_) {
    const Function* function = flow_graph.GetFunction(edge.target_);
    *stream << FormatAddress(edge.function_->GetEntryPoint()) << ":"
            << FormatAddress(edge.source_) << " -> "
            << FormatAddress(edge.target_) << "    "
            << edge.function_->GetName(Function::DEMANGLED) << " -> "
            << (function ? function->GetName(Function::DEMANGLED) : "") << "\n";
  }
}

CallGraph::CallGraph() { ++instance_count_; }

CallGraph::~CallGraph() {
  --instance_count_;
  if (instance_count_ == 0) {
    StringCache().swap(string_cache_);
  }
}

const std::string* CallGraph::CacheString(const std::string& text) {
  return &*string_cache_.insert(text).first;
}

void CallGraph::AddFunction(Address address) { functions_.insert(address); }

void CallGraph::AddEdge(Address source, Address target) {
  edges_.push_back(EdgeInfo(0, source, target));
}

void CallGraph::ScheduleEdgeAdd(Function* function, Address source,
                                Address target) {
  temp_edges_.push_back(EdgeInfo(function, source, target));
}

void CallGraph::SortEdges() { std::sort(edges_.begin(), edges_.end()); }

void CallGraph::CommitEdges() {
  std::copy(temp_edges_.begin(), temp_edges_.end(),
            std::back_inserter<Edges>(edges_));
  Edges().swap(temp_edges_);

  edges_.erase(std::remove_if(edges_.begin(), edges_.end(), EdgeFunctionIsNull),
               edges_.end());  // Remove edges without source functions.
  SortEdges();

  // Remove duplicates.
  edges_.erase(std::unique(edges_.begin(), edges_.end()), edges_.end());
}

int CallGraph::DeleteInvalidFunctions(FlowGraph* flow_graph) {
  // Delete all edges with invalid source or target functions.
  edges_.erase(std::remove_if(edges_.begin(), edges_.end(),
                              [&flow_graph](const EdgeInfo& edge) {
                                // The source function must exist and be valid.
                                const Function* source = edge.function_;
                                if (!source || source->GetTypeHeuristic() ==
                                                   Function::TYPE_INVALID) {
                                  return true;
                                }

                                // The target function must not exist or be
                                // valid. The "target not exist" case covers
                                // calls into imported functions such as
                                // operating system dlls.
                                const Function* target =
                                    flow_graph->GetFunction(edge.target_);
                                return target && target->GetTypeHeuristic() ==
                                                     Function::TYPE_INVALID;
                              }),
               edges_.end());

  int num_invalid_functions = 0;
  for (auto function = flow_graph->GetFunctions().begin();
       function != flow_graph->GetFunctions().end();) {
    if (function->second->GetTypeHeuristic() == Function::TYPE_INVALID) {
      functions_.erase(function->first);
      delete function->second;
      // Note: btree_map<>::erase() invalidates iterators
      function = flow_graph->GetFunctions().erase(function);
      ++num_invalid_functions;
    } else {
      function++;
    }
  }

  return num_invalid_functions;
}

CallGraph::Edges::const_iterator CallGraph::GetEdges(Address source) const {
  EdgeInfo edge(0, source, 0);
  Edges::const_iterator i =
      std::lower_bound(edges_.begin(), edges_.end(), edge);
  return i != edges_.end() && i->source_ == source ? i : edges_.end();
}

CallGraph::FunctionEntryPoints& CallGraph::GetFunctions() { return functions_; }

const CallGraph::FunctionEntryPoints& CallGraph::GetFunctions() const {
  return functions_;
}

const CallGraph::Edges& CallGraph::GetEdges() const { return edges_; }

CallGraph::Edges& CallGraph::GetEdges() { return edges_; }
const Comments& CallGraph::GetComments() const { return comments_; }

Comments& CallGraph::GetComments() { return comments_; }

std::pair<Comments::const_iterator, Comments::const_iterator>
CallGraph::GetComments(Address address) const {
  return std::equal_range(comments_.begin(), comments_.end(),
                          Comment(address, 0, nullptr, Comment::REGULAR),
                          &SortComments);
}

void CallGraph::AddComment(Address address, size_t operand,
                           const std::string& comment, Comment::Type type,
                           bool repeatable) {
  comments_.push_back(
      Comment(address, operand, CacheString(comment), type, repeatable));
}

size_t CallGraph::GetStringReference(Address address) const {
  auto it = string_references_.find(address);
  if (it != string_references_.end()) {
    return it->second;
  }
  return 0;
}

void CallGraph::AddStringReference(Address address, const std::string& ref) {
  if (ref.empty()) {
    return;
  }

  // TODO(jduart): Concat multiple hashes.
  string_references_[address] = GetSdbmHash(ref);
}

// Fold the strings of all comments that are of type regular and share the same
// address, since the database schema doesn't allow more than one comment per
// address.
void CallGraph::PostProcessComments() {
  std::stable_sort(comments_.begin(), comments_.end(), &SortComments);
  FoldComments();
}

// Removes comments with identical addresses and combines their strings but
// only if both are regular comments, since this is the only comment type that
// is actually written to the database.
// This method assumes that the comments are sorted by address.
void CallGraph::FoldComments() {
  if (comments_.empty()) {
    return;
  }

  Comments::iterator first = comments_.begin();
  const Comments::iterator last = comments_.end();
  Comments::iterator result = first;
  while (++first != last) {
    if (!AreDuplicateRegularComments(*result, *first)) {
      *(++result) = *first;
    } else {
      std::string accumulated_comment(*result->comment);
      while (first != last && AreDuplicateRegularComments(*result, *first)) {
        accumulated_comment.append("\n");
        accumulated_comment.append(*first->comment);
        ++first;
      }
      --first;
      result->comment = CacheString(accumulated_comment);
    }
  }
  comments_.erase(++result, comments_.end());
}
