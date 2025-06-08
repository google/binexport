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

#include "third_party/zynamics/binexport/operand.h"

#include <cstdint>
#include <string>

#include "third_party/absl/log/check.h"

thread_local Expressions Operand::expressions_;
thread_local Operand::OperandCache Operand::operand_cache_;
thread_local uint32_t Operand::global_id_ = 0;

// Delete unreferenced operands from cache and relabel surviving ones so we'll
// have continuous ids again.
void Operand::PurgeCache(const absl::flat_hash_set<int>& ids_to_keep) {
  int new_id = 0;
  for (auto it = operand_cache_.begin(), end = operand_cache_.end();
       it != end;) {
    if (!ids_to_keep.contains(it->second.id_)) {
      operand_cache_.erase(it++);
    } else {
      it->second.id_ = ++new_id;
      ++it;
    }
  }
}

Operand::Operand(const Expressions& expressions)
    : expression_index_(static_cast<uint32_t>(expressions_.size())),
      expression_count_(static_cast<uint8_t>(expressions.size())) {
  expressions_.insert(expressions_.end(), expressions.begin(),
                      expressions.end());
}

Operand* Operand::CreateOperand(const Expressions& expressions) {
  std::string signature;
  signature.reserve(expressions.size() * 18 /* bytes for a single signature */);
  for (auto* expression : expressions) {
    signature.append(expression->CreateSignature());
  }

  if (auto it = operand_cache_.find(signature); it != operand_cache_.end()) {
    return &it->second;
  }

  Operand operand(expressions);
  // Simply count how many objects are already in the cache.
  operand.id_ = ++global_id_;
  return &operand_cache_.emplace(signature, operand).first->second;
}

void Operand::EmptyCache() {
  Expressions().swap(expressions_);
  OperandCache().swap(operand_cache_);
  global_id_ = 0;
}

const Operand::OperandCache& Operand::GetOperands() { return operand_cache_; }

int Operand::GetId() const { return id_; }

Expressions::const_iterator Operand::cbegin() const {
  return expressions_.begin() + expression_index_;
}

Expressions::const_iterator Operand::cend() const {
  return begin() + expression_count_;
}

Expressions::iterator Operand::begin() const {
  return expressions_.begin() + expression_index_;
}

Expressions::iterator Operand::end() const {
  return begin() + expression_count_;
}

uint8_t Operand::GetExpressionCount() const { return expression_count_; }

const Expression& Operand::GetExpression(int index) const {
  CHECK(index >= 0 && index < GetExpressionCount());
  return *expressions_[expression_index_ + index];
}

const Expression& Operand::GetLastExpression() const {
  return GetExpression(GetExpressionCount() - 1);
}
