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

import com.google.security.zynamics.BinExport.BinExport2;
import ghidra.app.util.DomainObjectService;
import ghidra.app.util.Option;
import ghidra.app.util.OptionException;
import ghidra.app.util.exporter.Exporter;
import ghidra.app.util.exporter.ExporterException;
import ghidra.framework.model.DomainObject;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Program;
import ghidra.util.exception.CancelledException;
import ghidra.util.task.TaskMonitor;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

/**
 * Exports Ghidra disassembly data into BinExport v2 format.
 *
 * @author Christian Blichmann
 */
public class BinExportExporter extends Exporter {

  /** Stringized version number allowing for scriptable update. */
  private static final String BINEXPORT_VERSION = "12";

  private static final String BINEXPORT_COPYRIGHT =
      "BinExport " + BINEXPORT_VERSION + " (c)2019-2025 Google LLC";

  /** Display name that appears in the export dialog. */
  private static final String BINEXPORT_FORMAT_DISPLAY_NAME =
      "Binary BinExport (v2) for BinDiff";

  private static final String BINEXPORT_FILE_EXTENSION = "BinExport";

  // Option names
  private static final String IDAPRO_COMPAT_OPTGROUP = "IDA Pro Compatibility";
  private static final String IDAPRO_COMPAT_OPT_SUBTRACT_IMAGEBASE =
      "Subtract Imagebase";
  private static final String IDAPRO_COMPAT_OPT_REMAP_MNEMONICS =
      "Remap mnemonics";
  private static final String IDAPRO_COMPAT_OPT_PREPEND_NAMESPACE =
      "Prepend Namespace to Function Names";

  /** Whether to subtract the program image base from addresses for export. */
  private boolean subtractImagebase = false;

  /** Whether to remap Ghidra's mnemonics into IDA Pro style ones. */
  private boolean remapMnemonics = false;

  /** Whether to prepend "namespace::" to function names where the namespace is not "Global" */
  private boolean prependNamespace = false;

  public BinExportExporter() {
    super(BINEXPORT_FORMAT_DISPLAY_NAME, BINEXPORT_FILE_EXTENSION, null);
    log.appendMsg(BINEXPORT_COPYRIGHT);
  }

  @Override
  public boolean export(File file, DomainObject domainObj,
      AddressSetView addrSet, TaskMonitor monitor)
      throws ExporterException, IOException {

    if (!(domainObj instanceof Program)) {
      log.appendMsg("Unsupported type: " + domainObj.getClass().getName());
      return false;
    }
    var program = (Program) domainObj;

    if (addrSet == null) {
      addrSet = program.getMemory();
    }

    monitor.setCancelEnabled(true);
    try {
      var builder = new BinExport2Builder(program, addrSet);
      if (remapMnemonics) {
        builder
            .setMnemonicMapper(new IdaProMnemonicMapper(program.getLanguage()));
      }
      if (subtractImagebase) {
        builder.setAddressOffset(program.getImageBase().getOffset());
      }
      if (prependNamespace) {
        builder.setPrependNamespace(true);
      }
      final BinExport2 proto = builder.build(monitor);

      monitor.setMessage("Writing BinExport2 file");
      try (var outputStream = new FileOutputStream(file)) {
        proto.writeTo(outputStream);
      }
    } catch (CancelledException e) {
      return false;
    }
    return true;
  }

  @Override
  @SuppressWarnings("JdkImmutableCollections")
  public List<Option> getOptions(DomainObjectService domainObjectService) {
    return List.of(
        new Option(IDAPRO_COMPAT_OPTGROUP, IDAPRO_COMPAT_OPT_SUBTRACT_IMAGEBASE, Boolean.FALSE),
        new Option(IDAPRO_COMPAT_OPTGROUP, IDAPRO_COMPAT_OPT_REMAP_MNEMONICS, Boolean.FALSE),
        new Option(IDAPRO_COMPAT_OPTGROUP, IDAPRO_COMPAT_OPT_PREPEND_NAMESPACE, Boolean.FALSE));
  }

  @Override
  public void setOptions(List<Option> options) throws OptionException {
    for (final var option : options) {
      switch (option.getName()) {
        case IDAPRO_COMPAT_OPT_SUBTRACT_IMAGEBASE:
          subtractImagebase = (boolean) option.getValue();
          break;
        case IDAPRO_COMPAT_OPT_REMAP_MNEMONICS:
          remapMnemonics = (boolean) option.getValue();
          break;
        case IDAPRO_COMPAT_OPT_PREPEND_NAMESPACE:
          prependNamespace = (boolean) option.getValue();
          break;
      }
    }
  }
}
