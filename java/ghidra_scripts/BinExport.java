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

// @category BinExport

import com.google.security.binexport.BinExport2Builder;
import com.google.security.binexport.IdaProMnemonicMapper;
import com.google.security.zynamics.BinExport.BinExport2;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.exporter.ExporterException;
import ghidra.framework.model.DomainObject;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Program;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

/**
 * Exports Ghidra disassembly data into BinExport v2 format.
 *
 * @author Andras Gemes
 * @author Christian Blichmann
 */
public class BinExport extends GhidraScript {

  /** Stringized version number allowing for scriptable update. */
  private static final String BINEXPORT_VERSION = "12";

  /** Copyright that appears in the console. */
  private static final String BINEXPORT_COPYRIGHT =
      "BinExport " + BINEXPORT_VERSION + " (c)2019-2024 Google LLC";

  /** Display name that appears in the console. */
  private static final String BINEXPORT_DISPLAY_NAME = "Binary BinExport (v2) for BinDiff";

  // Choice names
  /** Whether to subtract the program image base from addresses for export. */
  private static final String IDAPRO_COMPAT_OPT_SUBTRACT_IMAGEBASE = "Subtract Imagebase";

  /** Whether to remap Ghidra's mnemonics to IDA Pro style ones. */
  private static final String IDAPRO_COMPAT_OPT_REMAP_MNEMONICS = "Remap mnemonics";

  /** Whether to prepend "namespace::" to function names where the namespace is not "Global" */
  private static final String IDAPRO_COMPAT_OPT_PREPEND_NAMESPACE =
      "Prepend Namespace to Function Names";

  @Override
  protected void run() throws Exception {
    println(BINEXPORT_DISPLAY_NAME);
    println(BINEXPORT_COPYRIGHT);
    File outputFile = askFile("Choose export file", "Export");

    List<String> choices =
        askChoices(
            "Choose options",
            "IDA Pro Compatibility",
            Arrays.asList(
                IDAPRO_COMPAT_OPT_SUBTRACT_IMAGEBASE,
                IDAPRO_COMPAT_OPT_REMAP_MNEMONICS,
                IDAPRO_COMPAT_OPT_PREPEND_NAMESPACE));

    DomainObject domainObj = currentProgram;
    AddressSetView addrSet = currentProgram.getMemory();

    if (!export(outputFile, domainObj, addrSet, choices)) {
      printerr("Export failed");
    } else {
      println("Export successful");
    }
  }

  public boolean export(
      File file, DomainObject domainObj, AddressSetView addrSet, List<String> selectedOptions)
      throws ExporterException, IOException {

    if (!(domainObj instanceof Program)) {
      printerr("Unsupported type: " + domainObj.getClass().getName());
      return false;
    }

    Program program = (Program) domainObj;

    var builder = new BinExport2Builder(program, addrSet);

    if (selectedOptions.contains(IDAPRO_COMPAT_OPT_REMAP_MNEMONICS)) {
      builder.setMnemonicMapper(new IdaProMnemonicMapper(program.getLanguage()));
    }
    if (selectedOptions.contains(IDAPRO_COMPAT_OPT_SUBTRACT_IMAGEBASE)) {
      builder.setAddressOffset(program.getImageBase().getOffset());
    }
    if (selectedOptions.contains(IDAPRO_COMPAT_OPT_PREPEND_NAMESPACE)) {
      builder.setPrependNamespace(true);
    }

    final BinExport2 proto = builder.build();

    println("Writing BinExport2 file");
    try (var outputStream = new FileOutputStream(file)) {
      proto.writeTo(outputStream);
    }

    return true;
  }
}
