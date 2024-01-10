// Copyright 2011-2024 Google LLC
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

#ifndef IDA_PLUGIN_H_
#define IDA_PLUGIN_H_

#include <cstddef>
#include <cstdint>

// clang-format off
#include "third_party/zynamics/binexport/ida/begin_idasdk.inc"  // NOLINT
#include <idp.hpp>                                              // NOLINT
#include <loader.hpp>                                           // NOLINT
#include "third_party/zynamics/binexport/ida/end_idasdk.inc"    // NOLINT
// clang-format on

namespace security::binexport {

// Simple CRTP-style template that can be used to implement IDA Pro plugins.
// Since IDA plugins are singletons, this design allows to avoid global
// variables for keeping plugin state.
template <typename T>
class IdaPlugin {
 public:
  virtual ~IdaPlugin() = default;

  IdaPlugin(const IdaPlugin&) = delete;
  IdaPlugin& operator=(const IdaPlugin&) = delete;

  static T* instance() {
    static auto* instance = new T();
    return instance;
  }

  // Initializes the plugin and registers it with IDA Pro. Returns nullptr on
  // error, in which case the plugin will be skipped.
  static plugmod_t* Register() {
    return instance()->Init() ? new PluginContext() : nullptr;
  }

  // Performs plugin initalization. Returns true on success, false otherwise.
  // Care must be taken with functions/libraries that should only be
  // called/initialized once per process. Since IDA 8.0, all new-style plugins
  // have PLUGIN_MULTI semantics, which means Init() will be called once per
  // database.
  // Note: Since the IdaPlugin class does not initialize logging, returning
  //       absl::Status makes little sense here.
  virtual bool Init() { return true; }

  virtual bool Run(size_t argument) = 0;
  virtual void Terminate() {}

 protected:
  class PluginContext : public plugmod_t {
   public:
    ~PluginContext() override { instance()->Terminate(); }

    bool idaapi run(size_t argument) override {
      return instance()->Run(argument);
    }
  };

  IdaPlugin() = default;
};

}  // namespace security::binexport

#endif  // IDA_PLUGIN_H_
