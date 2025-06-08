// Copyright 2019-2025 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package com.google.security.binexport;

import ghidra.program.model.listing.Instruction;

/** Remaps Ghidra instruction mnemonics. */
public interface MnemonicMapper {

  /**
   * Returns the remapped instruction mnemonic for a Ghidra instruction.
   *
   * <p>The default implementation maps each instruction to itself.
   */
  default String getInstructionMnemonic(Instruction instr) {
    return instr.getMnemonicString();
  }
}
