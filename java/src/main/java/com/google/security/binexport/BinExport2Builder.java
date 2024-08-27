// Copyright 2019-2024 Google LLC
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

import static java.util.stream.Collectors.joining;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import com.google.protobuf.ByteString;
import com.google.security.zynamics.BinExport.BinExport2;
import com.google.security.zynamics.BinExport.BinExport2.Builder;
import ghidra.app.nav.NavigationUtils;
import ghidra.program.database.symbol.EquateDB;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.block.BasicBlockModel;
import ghidra.program.model.block.CodeBlock;
import ghidra.program.model.block.CodeBlockReference;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.lang.OperandType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.CodeUnitFormat;
import ghidra.program.model.listing.CodeUnitFormatOptions;
import ghidra.program.model.listing.CodeUnitIterator;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.LabelString;
import ghidra.program.model.listing.Library;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.listing.OperandRepresentationList;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.Program;
import ghidra.program.model.listing.VariableOffset;
import ghidra.program.model.mem.MemoryAccessException;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.FlowType;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolUtilities;
import ghidra.program.util.DefinedDataIterator;
import ghidra.util.exception.CancelledException;
import ghidra.util.task.TaskMonitor;
import java.io.File;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Optional;
import java.util.TreeMap;
import java.util.function.ToIntFunction;
import util.CollectionUtils;

/**
 * Java implementation of the BinExport2 writer class for Ghidra using a builder pattern.
 *
 * @author Christian Blichmann
 */
public class BinExport2Builder {
  private final Builder builder = BinExport2.newBuilder();

  private TaskMonitor monitor;

  private final Program program;
  private final AddressSetView addrSet;
  private final Listing listing;
  private final BasicBlockModel bbModel;

  private MnemonicMapper mnemonicMapper = new IdentityMnemonicMapper();
  private long addressOffset = 0;
  private boolean prependNamespace = false;
  private final Map<Address, Address> externalLinkageAddressMapping = new HashMap<>();

  private final HashMap<BinExport2.Expression, Integer> expressionIndices = new HashMap<>();
  private final HashMap<BinExport2.Operand, Integer> operandIndices = new HashMap<>();
  private final HashMap<String, Integer> stringIndices = new HashMap<>();

  public BinExport2Builder(Program ghidraProgram, AddressSetView ghidraAddrSet) {
    program = ghidraProgram;
    addrSet = ghidraAddrSet;
    listing = program.getListing();
    bbModel = new BasicBlockModel(program, true);
  }

  public BinExport2Builder setMnemonicMapper(MnemonicMapper mapper) {
    mnemonicMapper = mapper;
    return this;
  }

  public BinExport2Builder setAddressOffset(long offset) {
    addressOffset = offset;
    return this;
  }

  public BinExport2Builder setPrependNamespace(boolean isPrepended) {
    prependNamespace = isPrepended;
    return this;
  }

  private Address getAddressFromLong(long offset) {
    return program.getAddressFactory().getDefaultAddressSpace().getAddress(offset);
  }

  private long getMappedAddress(Address address) {
    return address.getOffset() - addressOffset;
  }

  private long getMappedAddress(Instruction instr) {
    return getMappedAddress(instr.getAddress());
  }

  private Address getExternalLinkageAddress(Address extAddr) {
    // External addresses exist in the EXTERNAL address space e.g. EXTERNAL:00000001
    // We must map these to the linkage address referenced by instructions
    return externalLinkageAddressMapping.computeIfAbsent(
        extAddr,
        address -> {
          // https://github.com/NationalSecurityAgency/ghidra/discussions/6080
          Address[] linkAddrs = NavigationUtils.getExternalLinkageAddresses(program, address);
          return linkAddrs.length != 0 ? linkAddrs[0] : null;
        });
  }

  private void buildMetaInformation() {
    monitor.setIndeterminate(true);
    monitor.setMessage("Exporting meta data");

    // Ghidra uses a quad format like x86:LE:32:default, BinExport just keeps
    // the processor and address size.
    String[] quad = program.getLanguageID().toString().split(":", 4);
    // TODO(cblichmann): Canonicalize architecture names
    String arch = quad[0] + "-" + quad[2];

    builder
        .getMetaInformationBuilder()
        .setExecutableName(new File(program.getExecutablePath()).getName())
        .setExecutableId(program.getExecutableSHA256())
        .setArchitectureName(arch)
        .setTimestamp(System.currentTimeMillis() / 1000);
  }

  static final ImmutableMap<String, Integer> OPERAND_SIZE_PREFIX_MAP =
      ImmutableMap.of(
          "byte ptr ", 1,
          "word ptr ", 2,
          "dword ptr ", 4,
          "qword ptr ", 8,
          "tword ptr ", 10,
          "xmmword ptr ", 16);

  static final ImmutableSet<String> OPERAND_SHIFT_SYMBOLS =
      ImmutableSet.of("asr", "lsl", "lsr", "ror", "rrx");
  static final ImmutableSet<String> OPERAND_CONDITION_SYMBOLS =
      ImmutableSet.of(
          "eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt",
          "le", "al");
  // Ghidra separates operands of an instruction already for us.
  // The separators and brackets don't and are difficult to represent any semantically meanings.
  // Instead, it only helps to determine the priorities of expression tree nodes.
  static final ImmutableSet<Character> OPERAND_SEPARATORS = ImmutableSet.of('+', ',', ':', '*');
  static final ImmutableList<Character> OPERAND_OPEN_BRACKETS = ImmutableList.of('{', '[');
  static final ImmutableList<Character> OPERAND_CLOSE_BRACKETS = ImmutableList.of('}', ']');

  private Integer getOrAddExpression(BinExport2.Expression expr) {
    int exprId = builder.getExpressionCount();
    var exprIndex = expressionIndices.putIfAbsent(expr, exprId);
    if (exprIndex == null) {
      builder.addExpression(expr);
      return exprId;
    }
    return exprIndex;
  }

  private Integer getOrAddStringTable(String str) {
    int strId = builder.getStringTableCount();
    var strIndex = stringIndices.putIfAbsent(str, strId);
    if (strIndex == null) {
      builder.addStringTable(str);
      return strId;
    }
    return strIndex;
  }

  private Optional<Integer> addCommentedExpression(
      BinExport2.Expression.Builder exprBuilder,
      Object markupToken,
      Object valueToken,
      List<BinExport2.Comment.Builder> comments,
      int opExprIndex) {
    if (markupToken.toString().equals(valueToken.toString())) {
      return Optional.empty();
    }

    BinExport2.Comment.Type commentType;
    if (markupToken instanceof VariableOffset) {
      commentType = BinExport2.Comment.Type.LOCAL_REFERENCE;
    } else if (markupToken instanceof OperandRepresentationList) {
      commentType = BinExport2.Comment.Type.DEFAULT;
    } else if (markupToken instanceof EquateDB) {
      commentType = BinExport2.Comment.Type.DEFAULT;
    } else if (markupToken instanceof LabelString) {
      var labelType = ((LabelString) markupToken).getLabelType();
      if (labelType == LabelString.CODE_LABEL) {
        commentType = BinExport2.Comment.Type.GLOBAL_REFERENCE;
      } else if (labelType == LabelString.VARIABLE) {
        commentType = BinExport2.Comment.Type.LOCAL_REFERENCE;
      } else if (labelType == LabelString.EXTERNAL) {
        commentType = BinExport2.Comment.Type.DEFAULT;
      } else {
        return Optional.empty();
      }
    } else {
      return Optional.empty();
    }

    var comment =
        BinExport2.Comment.newBuilder()
            .setOperandExpressionIndex(opExprIndex)
            .setRepeatable(false)
            .setType(commentType);
    if (valueToken instanceof Register) {
      exprBuilder =
          exprBuilder.setType(BinExport2.Expression.Type.REGISTER).setSymbol(valueToken.toString());
    } else if (valueToken instanceof Scalar) {
      exprBuilder =
          exprBuilder
              .setType(BinExport2.Expression.Type.IMMEDIATE_INT)
              .setImmediate(((Scalar) valueToken).getValue())
              // Set the symbol field to be backwards-compatible.
              .setSymbol(markupToken.toString());
    } else if (valueToken instanceof Address) {
      exprBuilder =
          exprBuilder
              .setType(BinExport2.Expression.Type.IMMEDIATE_INT)
              .setImmediate(((Address) valueToken).getOffset())
              // Set the symbol field to be backwards-compatible.
              .setSymbol(markupToken.toString());
    } else {
      // Character, String
      exprBuilder =
          exprBuilder.setType(BinExport2.Expression.Type.SYMBOL).setSymbol(valueToken.toString());
    }
    var strIdx = getOrAddStringTable(markupToken.toString());
    comments.add(comment.setStringTableIndex(strIdx));
    return Optional.of(getOrAddExpression(exprBuilder.build()));
  }

  private void buildOperandExpressions(
      Integer startOffset,
      Integer endOffset,
      Integer operandType,
      ImmutableList<? extends Object> operandList,
      ImmutableList<? extends Object> operandMarkupList,
      Integer parentId,
      List<Integer> opExprIndices,
      Boolean addComment,
      List<BinExport2.Comment.Builder> comments) {
    if (startOffset >= endOffset) {
      return;
    }

    var exprBuilder = BinExport2.Expression.newBuilder();
    if (parentId != null) {
      exprBuilder.setParentIndex(parentId);
    }

    // Find shift keywords
    var operandSubstring =
        operandMarkupList.subList(startOffset, endOffset).stream()
            .map(Object::toString)
            .collect(joining(""))
            .toLowerCase(Locale.getDefault());

    for (var symbol : OPERAND_SHIFT_SYMBOLS) {
      if (!operandSubstring.startsWith(symbol)) {
        continue;
      }
      var expr = exprBuilder.setType(BinExport2.Expression.Type.OPERATOR).setSymbol(symbol).build();
      var nextParentId = getOrAddExpression(expr);
      opExprIndices.add(nextParentId);
      buildOperandExpressions(
          startOffset + symbol.length(),
          endOffset,
          operandType,
          operandList,
          operandMarkupList,
          nextParentId,
          opExprIndices,
          addComment,
          comments);
      return;
    }

    // Find Condition keywords
    if (OperandType.isFlag(operandType)) {
      for (var symbol : OPERAND_CONDITION_SYMBOLS) {
        if (!operandSubstring.startsWith(symbol)) {
          continue;
        }
        var expr =
            exprBuilder.setType(BinExport2.Expression.Type.OPERATOR).setSymbol(symbol).build();
        var nextParentId = getOrAddExpression(expr);
        opExprIndices.add(nextParentId);
        buildOperandExpressions(
            startOffset + symbol.length(),
            endOffset,
            operandType,
            operandList,
            operandMarkupList,
            nextParentId,
            opExprIndices,
            addComment,
            comments);
        return;
      }
    }

    // Find first non-enclosing separator
    var openClosure = 0;
    for (var i = startOffset; i < endOffset; i++) {
      var token = operandMarkupList.get(i);

      if (!(token instanceof Character)) {
        continue;
      }
      if (OPERAND_OPEN_BRACKETS.contains(token)) {
        openClosure++;
        continue;
      }
      if (OPERAND_CLOSE_BRACKETS.contains(token)) {
        openClosure--;
        continue;
      }
      if (openClosure == 0 && OPERAND_SEPARATORS.contains(token)) {
        var expr =
            exprBuilder
                .setType(BinExport2.Expression.Type.OPERATOR)
                .setSymbol(token.toString())
                .build();
        var separatorId = getOrAddExpression(expr);
        opExprIndices.add(separatorId);
        buildOperandExpressions(
            startOffset,
            i,
            operandType,
            operandList,
            operandMarkupList,
            separatorId,
            opExprIndices,
            addComment,
            comments);
        buildOperandExpressions(
            i + 1,
            endOffset,
            operandType,
            operandList,
            operandMarkupList,
            separatorId,
            opExprIndices,
            addComment,
            comments);
        return;
      }
    }
    // Strips trailing whitespaces
    // Adds operator for trailing "!"
    var lastToken = operandMarkupList.get(endOffset - 1);
    if (lastToken instanceof Character) {
      var ch = (Character) lastToken;
      if (Character.isWhitespace(ch.charValue()) || ch.charValue() == '!') {
        var nextParentId = parentId;
        if (ch.charValue() == '!') {
          var expr =
              exprBuilder.setType(BinExport2.Expression.Type.OPERATOR).setSymbol("!").build();
          nextParentId = getOrAddExpression(expr);
          opExprIndices.add(nextParentId);
        }
        buildOperandExpressions(
            startOffset,
            endOffset - 1,
            operandType,
            operandList,
            operandMarkupList,
            nextParentId,
            opExprIndices,
            addComment,
            comments);
        return;
      }
    }
    // Adds other operands sequentially.
    var firstToken = operandMarkupList.get(startOffset);
    var nextParentId = parentId;
    if (firstToken instanceof Character) {
      var ch = (Character) firstToken;

      // Add brackets enclosed expressions
      var bracketIndex = OPERAND_OPEN_BRACKETS.indexOf(ch);
      if (bracketIndex >= 0) {
        var matchedClosure = 0;
        for (var j = startOffset; j < endOffset; j++) {
          var token = operandMarkupList.get(j);
          if (!(token instanceof Character)) {
            continue;
          }
          if (OPERAND_OPEN_BRACKETS.get(bracketIndex).equals(token)) {
            matchedClosure++;
          }
          if (OPERAND_CLOSE_BRACKETS.get(bracketIndex).equals(token)) {
            matchedClosure--;
          }
          if (matchedClosure == 0) {
            var expr =
                exprBuilder
                    .setType(BinExport2.Expression.Type.DEREFERENCE)
                    .setSymbol(ch.toString())
                    .build();
            nextParentId = getOrAddExpression(expr);
            opExprIndices.add(nextParentId);
            buildOperandExpressions(
                startOffset + 1,
                j,
                operandType,
                operandList,
                operandMarkupList,
                nextParentId,
                opExprIndices,
                addComment,
                comments);
            buildOperandExpressions(
                j + 1,
                endOffset,
                operandType,
                operandList,
                operandMarkupList,
                parentId,
                opExprIndices,
                addComment,
                comments);
            return;
          }
        }
      }

      if (ch.charValue() == '-') {
        var expr = exprBuilder.setType(BinExport2.Expression.Type.OPERATOR).setSymbol("*").build();
        nextParentId = getOrAddExpression(expr);
        opExprIndices.add(nextParentId);
        var negationExpr =
            BinExport2.Expression.newBuilder()
                .setParentIndex(nextParentId)
                .setType(BinExport2.Expression.Type.IMMEDIATE_INT)
                .setImmediate(-1)
                .build();
        opExprIndices.add(getOrAddExpression(negationExpr));
      } else if (!Character.isWhitespace(ch.charValue()) && ch.charValue() != '#') {
        var expr =
            exprBuilder.setType(BinExport2.Expression.Type.SYMBOL).setSymbol(ch.toString()).build();
        nextParentId = getOrAddExpression(expr);
        opExprIndices.add(nextParentId);
      }
    } else if (firstToken instanceof Register) {
      var expr =
          exprBuilder
              .setType(BinExport2.Expression.Type.REGISTER)
              .setSymbol(firstToken.toString())
              .build();
      nextParentId = getOrAddExpression(expr);
      opExprIndices.add(nextParentId);
    } else if (firstToken instanceof Scalar) {
      var expr =
          exprBuilder
              .setType(BinExport2.Expression.Type.IMMEDIATE_INT)
              .setImmediate(((Scalar) firstToken).getValue())
              .build();
      nextParentId = getOrAddExpression(expr);
      opExprIndices.add(nextParentId);
    } else if (firstToken instanceof Address) {
      var expr =
          exprBuilder
              .setType(BinExport2.Expression.Type.IMMEDIATE_INT)
              .setImmediate(((Address) firstToken).getOffset())
              .build();
      nextParentId = getOrAddExpression(expr);
      opExprIndices.add(nextParentId);
    } else {
      // String, List, VariableOffset, LabelString, etc.
      Optional<Integer> commentedExprId = Optional.empty();
      if (addComment) {
        commentedExprId =
            addCommentedExpression(
                exprBuilder,
                firstToken,
                operandList.get(startOffset),
                comments,
                opExprIndices.size());
      }
      if (commentedExprId.isPresent()) {
        nextParentId = commentedExprId.get();
        opExprIndices.add(nextParentId);
      } else {
        var expr =
            exprBuilder
                .setType(BinExport2.Expression.Type.SYMBOL)
                .setSymbol(firstToken.toString())
                .build();
        nextParentId = getOrAddExpression(expr);
        opExprIndices.add(nextParentId);
      }
    }
    buildOperandExpressions(
        startOffset + 1,
        endOffset,
        operandType,
        operandList,
        operandMarkupList,
        nextParentId,
        opExprIndices,
        addComment,
        comments);
  }

  private ImmutableList<Integer> buildInstructionOperands(
      Instruction instr, CodeUnitFormat cuf, List<BinExport2.Comment.Builder> comments) {
    int operandId = builder.getOperandCount();
    var opIndices = new ArrayList<Integer>();
    for (int i = 0; i < instr.getNumOperands(); i++) {
      var operandComments = new ArrayList<BinExport2.Comment.Builder>();
      var operandString = cuf.getOperandRepresentationString(instr, i);
      var operandMarkupList = ImmutableList.copyOf(cuf.getOperandRepresentationList(instr, i));
      var operandList = ImmutableList.copyOf(instr.getDefaultOperandRepresentationList(i));
      Boolean addComment = operandMarkupList.size() == operandList.size();

      Integer parentId = null;
      Integer startOffset = 0;
      var opExprIndices = new ArrayList<Integer>();

      // Add size prefix if applicable
      // Ghidra uses {@code java.lang.Character} to store each char of
      // the size prefixes like "q", "w", "o", "r", "d", " ", "p", "t", "r", " "
      for (var entry : OPERAND_SIZE_PREFIX_MAP.entrySet()) {
        if (!operandString.startsWith(entry.getKey())) {
          continue;
        }
        var expr =
            BinExport2.Expression.newBuilder()
                .setType(BinExport2.Expression.Type.SIZE_PREFIX)
                .setSymbol("b" + entry.getValue())
                .build();
        parentId = getOrAddExpression(expr);
        opExprIndices.add(parentId);
        startOffset += entry.getKey().length();
        break;
      }
      buildOperandExpressions(
          startOffset,
          operandMarkupList.size(),
          instr.getOperandType(i),
          operandList,
          operandMarkupList,
          parentId,
          opExprIndices,
          addComment,
          operandComments);

      BinExport2.Operand operand =
          BinExport2.Operand.newBuilder().addAllExpressionIndex(opExprIndices).build();
      var opIndex = operandIndices.putIfAbsent(operand, operandId);

      var opIdx = opIndices.size();
      for (var comment : operandComments) {
        comment.setInstructionOperandIndex(opIdx);
        comments.add(comment);
      }

      if (opIndex == null) {
        opIndices.add(operandId);
        operandId++;
        builder.addOperand(operand);
      } else {
        opIndices.add(opIndex);
      }
    }
    return ImmutableList.copyOf(opIndices);
  }

  private void buildMnemonics(Map<String, Integer> mnemonicIndices) {
    monitor.setIndeterminate(true);
    monitor.setMessage("Computing mnemonic histogram");
    var mnemonicHist = new HashMap<String, Integer>();
    for (Instruction instr : listing.getInstructions(true)) {
      mnemonicHist.merge(mnemonicMapper.getInstructionMnemonic(instr), 1, Integer::sum);
    }
    var mnemonicList = new ArrayList<>(mnemonicHist.entrySet());
    mnemonicList.sort(
        Comparator.comparingInt((ToIntFunction<Entry<String, Integer>>) Entry::getValue)
            .reversed()
            .thenComparing(Entry::getKey));
    int id = 0;
    for (var entry : mnemonicList) {
      builder.addMnemonicBuilder().setName(entry.getKey());
      mnemonicIndices.put(entry.getKey(), id++);
    }
  }

  private void buildInstructions(
      Map<String, Integer> mnemonics, Map<Long, Integer> instructionIndices) {
    monitor.setIndeterminate(false);
    monitor.setMessage("Exporting instructions");
    monitor.setMaximum(listing.getNumInstructions());
    var cuf = new CodeUnitFormat(new CodeUnitFormatOptions());
    int progress = 0;
    Instruction prevInstr = null;
    long prevAddress = 0;
    int prevSize = 0;
    for (Instruction instr : listing.getInstructions(true)) {
      var comments = new ArrayList<BinExport2.Comment.Builder>();

      long address = getMappedAddress(instr);

      var id = builder.getInstructionCount();
      var instrBuilder = builder.addInstructionBuilder();
      // Write the full instruction address iff:
      // - there is no previous instruction
      // - the previous instruction doesn't have code flow into the current one
      // - the previous instruction overlaps the current one
      // - the current instruction is a function entry point
      if (prevInstr == null
          || !prevInstr.hasFallthrough()
          || prevAddress + prevSize != address
          || listing.getFunctionAt(instr.getAddress()) != null) {
        instrBuilder.setAddress(address);
      }
      try {
        var bytes = instr.getBytes();
        instrBuilder.setRawBytes(ByteString.copyFrom(bytes));
        prevSize = bytes.length;
      } catch (MemoryAccessException e) {
        // Leave raw bytes empty
      }
      int mnemonicIndex = mnemonics.get(mnemonicMapper.getInstructionMnemonic(instr));
      if (mnemonicIndex != 0) {
        // Only store if different from default value
        instrBuilder.setMnemonicIndex(mnemonicIndex);
      }
      instructionIndices.put(address, id);

      instrBuilder.addAllOperandIndex(buildInstructionOperands(instr, cuf, comments));

      // Add all operand comments for this instruction.
      for (var comment : comments) {
        var commentIdx = builder.getCommentCount();
        builder.addComment(comment.setInstructionIndex(id).build());
        instrBuilder.addCommentIndex(commentIdx);
      }

      // Export call targets.
      for (Reference refFrom : instr.getReferencesFrom()) {
        RefType refType = refFrom.getReferenceType();
        if (!refType.isCall() && !refType.isJump()) {
          continue;
        }

        Address toAddr = refFrom.getToAddress();
        if (listing.getFunctionAt(toAddr) == null) {
          continue;
        }

        if (toAddr.isExternalAddress()) {
          toAddr = getExternalLinkageAddress(toAddr);
          if (toAddr == null) {
            continue;
          }
        }

        instrBuilder.addCallTarget(getMappedAddress(toAddr));
      }

      prevInstr = instr;
      prevAddress = address;
      monitor.setProgress(progress++);
    }
  }

  private void buildBasicBlocks(
      Map<Long, Integer> instructionIndices, Map<Long, Integer> basicBlockIndices)
      throws CancelledException {
    int id = 0;
    for (var bbIter = bbModel.getCodeBlocks(monitor); bbIter.hasNext(); ) {
      CodeBlock bb = bbIter.next();

      var protoBb = builder.addBasicBlockBuilder();

      int instructionIndex;
      int beginIndex = -1;
      int endIndex = -1;
      for (Instruction instr : listing.getInstructions(bb, true)) {
        instructionIndex = instructionIndices.get(getMappedAddress(instr));
        if (beginIndex < 0) {
          beginIndex = instructionIndex;
          endIndex = beginIndex + 1;
        } else if (instructionIndex != endIndex) {
          // Sequence is broken, store an interval
          var indexRange = protoBb.addInstructionIndexBuilder().setBeginIndex(beginIndex);
          if (endIndex != beginIndex + 1) {
            // Omit end index in the single instruction interval case
            indexRange.setEndIndex(endIndex);
          }
          beginIndex = instructionIndex;
          endIndex = beginIndex + 1;
        } else {
          // Sequence is unbroken, remember endIndex
          endIndex = instructionIndex + 1;
        }
      }
      var indexRange = protoBb.addInstructionIndexBuilder().setBeginIndex(beginIndex);
      if (endIndex != beginIndex + 1) {
        // Like above, omit end index in the single instruction interval case
        indexRange.setEndIndex(endIndex);
      }
      basicBlockIndices.put(getMappedAddress(bb.getFirstStartAddress()), id++);
    }
  }

  private void buildFlowGraphs(Map<Long, Integer> basicBlockIndices) throws CancelledException {
    FunctionManager funcManager = program.getFunctionManager();
    monitor.setIndeterminate(false);
    monitor.setMaximum(funcManager.getFunctionCount());
    int i = 0;

    for (Function func : funcManager.getFunctions(true)) {
      monitor.setProgress(i++);
      if (func.getEntryPoint().isNonLoadedMemoryAddress()) {
        continue;
      }

      var bbIter = bbModel.getCodeBlocksContaining(func.getBody(), monitor);
      if (!bbIter.hasNext()) {
        continue; // Skip empty flow graphs, they only exist as call graph nodes
      }
      var flowGraph = builder.addFlowGraphBuilder();
      while (bbIter.hasNext()) {
        CodeBlock bb = bbIter.next();
        long bbAddress = getMappedAddress(bb.getFirstStartAddress());
        int id = basicBlockIndices.get(bbAddress);
        if (bbAddress == getMappedAddress(func.getEntryPoint())) {
          flowGraph.setEntryBasicBlockIndex(id);
        }
        flowGraph.addBasicBlockIndex(id);

        long bbLastInstrAddress =
            getMappedAddress(listing.getInstructionBefore(bb.getMaxAddress()));
        var edges = new ArrayList<BinExport2.FlowGraph.Edge>();
        var lastFlow = RefType.INVALID;
        for (var bbDestIter = bb.getDestinations(monitor); bbDestIter.hasNext(); ) {
          CodeBlockReference bbRef = bbDestIter.next();
          // BinExport2 only stores flow from the very last instruction of a
          // basic block.
          if (getMappedAddress(bbRef.getReferent()) != bbLastInstrAddress) {
            continue;
          }

          var edge = BinExport2.FlowGraph.Edge.newBuilder();
          var targetId = basicBlockIndices.get(getMappedAddress(bbRef.getDestinationAddress()));
          FlowType flow = bbRef.getFlowType();
          if (flow.isConditional() || lastFlow.isConditional()) {
            edge.setType(
                    flow.isConditional()
                        ? BinExport2.FlowGraph.Edge.Type.CONDITION_TRUE
                        : BinExport2.FlowGraph.Edge.Type.CONDITION_FALSE)
                .setSourceBasicBlockIndex(id);
            if (targetId != null) {
              edge.setTargetBasicBlockIndex(targetId);
            }
            edges.add(edge.build());
          } else if (flow.isUnConditional() && !flow.isComputed()) {
            edge.setSourceBasicBlockIndex(id);
            if (targetId != null) {
              edge.setTargetBasicBlockIndex(targetId);
            }
            edges.add(edge.build());
          } else if (flow.isJump() && flow.isComputed()) {
            edge.setSourceBasicBlockIndex(id);
            if (targetId != null) {
              edge.setTargetBasicBlockIndex(targetId);
              edge.setType(BinExport2.FlowGraph.Edge.Type.SWITCH);
            }
            edges.add(edge.build());
          }
          lastFlow = flow;
        }
        flowGraph.addAllEdge(edges);
      }
      assert flowGraph.getEntryBasicBlockIndex() > 0;
    }
  }

  private void buildCallGraphAndModuleList() throws CancelledException {
    var callGraph = builder.getCallGraphBuilder();
    FunctionManager funcManager = program.getFunctionManager();
    monitor.setIndeterminate(false);
    monitor.setMaximum(funcManager.getFunctionCount() * 3L);
    int i = 0;
    int id = 0;
    TreeMap<Address, Function> orderedFunctions = new TreeMap<>();
    Map<Long, Integer> vertexIndices = new HashMap<>();
    Map<String, Integer> moduleIndices = new HashMap<>();

    // First round, create ordered function mapping because Ghidra does not guarantee the order of
    // external (imported) functions and BinExport requires ordered vertices
    for (Function func : funcManager.getFunctions(true)) {
      monitor.setProgress(i++);
      orderedFunctions.put(func.getEntryPoint(), func);
    }
    for (Function extFunc : funcManager.getExternalFunctions()) {
      monitor.setProgress(i++);
      Address linkAddr = getExternalLinkageAddress(extFunc.getEntryPoint());
      if (linkAddr != null) {
        orderedFunctions.put(linkAddr, extFunc);
      }
    }

    // Second round, gather vertex indices for all functions
    for (Map.Entry<Address, Function> entry : orderedFunctions.entrySet()) {
      monitor.setProgress(i++);
      Address funcEntryAddr = entry.getKey();
      Function func = entry.getValue();
      if (funcEntryAddr.isNonLoadedMemoryAddress()) {
        continue;
      }
      long mappedFuncEntryAddr = getMappedAddress(funcEntryAddr);

      var vertex = callGraph.addVertexBuilder().setAddress(mappedFuncEntryAddr);
      if (func.isThunk()) {
        vertex.setType(BinExport2.CallGraph.Vertex.Type.THUNK);
      }
      if (func.isExternal()) {
        vertex.setType(BinExport2.CallGraph.Vertex.Type.IMPORTED);
        // Add module mapping
        String moduleName = func.getParentNamespace().getName();
        if (!moduleName.equals(Library.UNKNOWN)) {
          if (moduleName.contains(".")) {
            moduleName = moduleName.substring(0, moduleName.lastIndexOf('.'));
          }
          Integer moduleId =
              moduleIndices.computeIfAbsent(
                  moduleName,
                  (String k) -> {
                    builder.addModuleBuilder().setName(k);
                    return builder.getModuleCount() - 1;
                  });
          vertex.setModuleIndex(moduleId);
        }
      }
      if (!func.getName().equals(SymbolUtilities.getDefaultFunctionName(func.getEntryPoint()))) {
        // Ghidra does not seem to provide both mangled and demangled names
        // (like IDA). Once the Demangle analyzer or DemangleAllScript has run,
        // function names will always appear demangled. Short of running the
        // demangler ourselves and comparing before/after names, there is no way
        // to distinguish mangled from demangled names.
        // Hence, the BinExport will have the names in the mangle_name field.

        // Mangled name is the default, optionally prefixed with namespace.
        vertex.setMangledName(getFunctionName(func));
      }
      vertexIndices.put(mappedFuncEntryAddr, id++);
    }

    // Third round, insert all call graph edges
    // Ignore external functions as we don't expect outgoing references
    for (Function func : funcManager.getFunctions(true)) {
      monitor.setProgress(i++);
      Address entryPoint = func.getEntryPoint();
      if (entryPoint.isNonLoadedMemoryAddress()) {
        continue;
      }
      id = vertexIndices.get(getMappedAddress(entryPoint));

      for (Function calledFunc : func.getCalledFunctions(monitor)) {
        Address calledFuncAddr = calledFunc.getEntryPoint();

        if (calledFuncAddr.isExternalAddress()) {
          calledFuncAddr = getExternalLinkageAddress(calledFuncAddr);
          if (calledFuncAddr == null) {
            continue;
          }
        }

        var targetId = vertexIndices.get(getMappedAddress(calledFuncAddr));
        if (targetId != null) {
          callGraph.addEdgeBuilder().setSourceVertexIndex(id).setTargetVertexIndex(targetId);
        }
      }
    }
  }

  private void buildDataReferences(Map<Long, Integer> instructionIndices) {
    monitor.setMessage("Exporting data references");
    monitor.setMaximum(instructionIndices.size());

    int i = 0;
    for (Map.Entry<Long, Integer> insnIndex : instructionIndices.entrySet()) {
      monitor.setProgress(i++);

      Address addr = getAddressFromLong(insnIndex.getKey());
      for (Reference ref : program.getReferenceManager().getReferencesFrom(addr)) {
        Address toAddr = ref.getToAddress();

        if (ref.isMemoryReference()
            && ref.getReferenceType().isData()
            && listing.getInstructionAt(toAddr) == null) {
          builder
              .addDataReferenceBuilder()
              .setInstructionIndex(insnIndex.getValue())
              .setAddress(getMappedAddress(toAddr));
        }
      }
    }
  }

  private void buildStrings(Map<Long, Integer> instructionIndices) {
    monitor.setMessage("Exporting strings");
    monitor.setIndeterminate(true);
    var strToInstr = new ArrayList<Map.Entry<Integer, Integer>>();

    for (Data data : CollectionUtils.asIterable(DefinedDataIterator.definedStrings(program))) {
      if (monitor.isCancelled()) {
        return;
      }

      var str = StringDataInstance.getStringDataInstance(data).getStringValue();
      if (str == null || str.isEmpty()) {
        continue;
      }

      int strIdx = getOrAddStringTable(str);

      for (Reference refTo : data.getReferenceIteratorTo()) {
        Instruction insn = listing.getInstructionAt(refTo.getFromAddress());
        if (insn == null) {
          continue;
        }

        long address = getMappedAddress(insn.getMinAddress());
        Integer instrIdx = instructionIndices.get(address);
        if (instrIdx == null) {
          continue;
        }

        strToInstr.add(Map.entry(strIdx, instrIdx));
      }
    }
    for (var entry : strToInstr) {
      builder
          .addStringReferenceBuilder()
          .setInstructionIndex(entry.getValue())
          .setStringTableIndex(entry.getKey());
    }
  }

  private void buildComments(Map<Long, Integer> instructionIndices) {
    monitor.setMessage("Exporting comments");
    monitor.setIndeterminate(true);

    var comments = new HashSet<String>();
    for (int commentType : ImmutableList.of(CodeUnit.EOL_COMMENT)) {
      for (CodeUnitIterator codeIt = listing.getCommentCodeUnitIterator(commentType, addrSet);
          codeIt.hasNext() && !monitor.isCancelled(); ) {
        CodeUnit code = codeIt.next();
        long address = getMappedAddress(code.getMinAddress());
        Integer instrIdx = instructionIndices.get(address);
        if (instrIdx == null) {
          continue;
        }

        var str = code.getComment(commentType);
        if (str == null || !comments.add(str)) {
          continue;
        }
        int strIdx = getOrAddStringTable(str);

        builder
            .addCommentBuilder()
            .setInstructionIndex(instrIdx)
            .setStringTableIndex(strIdx)
            .setRepeatable(false)
            .setType(BinExport2.Comment.Type.DEFAULT);
        int commentIdx = builder.getCommentCount() - 1;

        builder.getInstructionBuilder(instrIdx).addCommentIndex(commentIdx);
      }
    }
  }

  private void buildSections() {
    monitor.setMessage("Exporting sections");
    monitor.setIndeterminate(false);
    MemoryBlock[] blocks = program.getMemory().getBlocks();
    monitor.setMaximum(blocks.length);
    for (int i = 0; i < blocks.length; i++) {
      var block = blocks[i];
      builder
          .addSectionBuilder()
          .setAddress(block.getStart().getOffset())
          .setSize(block.getSize())
          .setFlagR(block.isRead())
          .setFlagW(block.isWrite())
          .setFlagX(block.isExecute());
      monitor.setProgress(i);
    }
  }

  /**
   * Parses a Ghidra instruction and outputs its components on stdout. Experimental.
   *
   * @param instr the instruction to parse.
   */
  @SuppressWarnings("unused")
  private void parseInstruction(Instruction instr) {
    if (instr.getAddress().getOffset() != 0x1420) {
      return;
    }

    var funMgr = program.getFunctionManager();
    var refMgr = program.getReferenceManager();

    System.out.printf(
        "%08X: %s (%s) ops:#%d{\n",
        instr.getAddress().getOffset(),
        instr.getMnemonicString(),
        instr.getLabel(),
        instr.getNumOperands());

    Function fun = funMgr.getFunctionContaining(instr.getAddress());
    var params =
        fun.getParameters(
            variable -> {
              var p = (Parameter) variable;
              Address addr = fun.getEntryPoint().add(p.getFirstUseOffset());
              System.out.printf(
                  "P: %s, %d, %08X %s\n",
                  p.getName(), p.getFirstUseOffset(), addr.getOffset(), p.getRegister());

              return instr.getAddress().equals(addr);
            });
    var cuf = new CodeUnitFormat(new CodeUnitFormatOptions());

    for (int i = 0; i < instr.getNumOperands(); i++) {
      Symbol[] syms = instr.getSymbols();

      System.out.printf("  sym:#%d[\n", syms.length);
      for (final var sym : syms) {
        System.out.printf("    \"%s\"", sym.toString());
      }
      System.out.print("  ]\n");

      Reference[] refs = instr.getOperandReferences(i);
      System.out.printf("  ref:#%d[\n", refs.length);
      for (var ref : refs) {
        var var = refMgr.getReferencedVariable(ref);
        System.out.printf("    \"%s\"", ref.toString());
        if (var != null) {
          System.out.printf(" (%s) @%s", var.getName(), var.getMinAddress().toString());
        }
        System.out.print("\n");
      }
      System.out.print("  ]\n");

      Object[] objs = instr.getOpObjects(i);
      System.out.printf("  obj:#%d[\n", objs.length);
      for (var obj : objs) {
        System.out.printf("    %s: \"%s\"", obj.getClass().getName(), obj);
        if (obj instanceof Register) {
          var reg = (Register) obj;
        } else if (obj instanceof Scalar) {
          var scalar = (Scalar) obj;
        }
        System.out.print("\n");
      }
      System.out.print("  ]\n");
      System.out.print(",\n");
    }
    System.out.print("}\n");
    throw new RuntimeException();
  }

  private String getFunctionName(Function function) {
    if (!prependNamespace) {
      return function.getName();
    }
    // Push all parent namespace names on top of the Vector.
    var functionNameComponents = new ArrayList<String>();
    var parentNamespace = function.getParentNamespace();
    while (parentNamespace != null && !"Global".equals(parentNamespace.getName())) {
      functionNameComponents.add(0, parentNamespace.getName());
      parentNamespace = parentNamespace.getParentNamespace();
    }
    // Add the name of the function as the last component.
    functionNameComponents.add(function.getName());
    return String.join("::", functionNameComponents);
  }

  public BinExport2 build(TaskMonitor taskMonitor) throws CancelledException {
    monitor = taskMonitor != null ? taskMonitor : TaskMonitor.DUMMY;

    buildMetaInformation();

    var mnemonics = new TreeMap<String, Integer>();
    buildMnemonics(mnemonics);
    var instructionIndices = new TreeMap<Long, Integer>();
    buildInstructions(mnemonics, instructionIndices);
    monitor.setMessage("Exporting basic block structure");
    var basicBlockIndices = new HashMap<Long, Integer>();
    buildBasicBlocks(instructionIndices, basicBlockIndices);

    buildComments(instructionIndices);
    buildStrings(instructionIndices);
    buildDataReferences(instructionIndices);

    monitor.setMessage("Exporting flow graphs");
    buildFlowGraphs(basicBlockIndices);
    monitor.setMessage("Exporting call graph");
    buildCallGraphAndModuleList();
    buildSections();

    return builder.build();
  }

  public BinExport2 build() {
    try {
      return build(TaskMonitor.DUMMY);
    } catch (final CancelledException e) {
      assert false : "TaskMonitor.DUMMY should not throw";
      throw new RuntimeException(e);
    }
  }
}
