if "%1" == "release" (
  echo Release build
) else (
  echo Continuous integration build
)

echo on

set SIGNTOOL="%ProgramFiles(x86)%\Windows kits\10\bin\x86\signtool.exe"

set BUILD_DIR=%cd%\build
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

:: Hermetic VS2022 (Community) toolchain using CMake and Ninja
unzip -q "%KOKORO_GFILE_DIR%\cmake-3.25.2-windows-x86_64.zip" -d "%BUILD_DIR%" || exit /b
unzip -q "%KOKORO_GFILE_DIR%\ninja-win.zip" -d "%BUILD_DIR%" || exit /b
unzip -q "%KOKORO_GFILE_DIR%\vs2022.zip" -d "%BUILD_DIR%" || exit /b
set CMAKE_BIN=%BUILD_DIR%\cmake-3.25.2-windows-x86_64\bin
set VS_PATH=%BUILD_DIR%\vs2022\14.33.31629
set SDK_PATH=%ProgramFiles(x86)%\Windows Kits\10
set SDK_VER=10.0.16299.0
set PATH=%SystemRoot%\system32;%VS_PATH%\bin\HostX64\x64;%SDK_PATH%\bin\%SDK_VER%\x64;%BUILD_DIR%;%CMAKE_BIN%
set LIB=%VS_PATH%\lib\x64;%SDK_PATH%\Lib\%SDK_VER%\um\x64;%SDK_PATH%\Lib\%SDK_VER%\ucrt\x64;
set INCLUDE=%VS_PATH%\include;%SDK_PATH%\Include\%SDK_VER%\ucrt;%SDK_PATH%\Include\%SDK_VER%\um;%SDK_PATH%\Include\%SDK_VER%\shared;%SDK_PATH%\Include\%SDK_VER%\winrt;%SDK_PATH%\Include\%SDK_VER%\cppwinrt

:: Build BinExport
set SRC_DIR=%KOKORO_ARTIFACTS_DIR%/git
set OUT_DIR=%BUILD_DIR%
set DEPS_DIR=%BUILD_DIR%

:: Copy extra Binary Ninja API dependency
xcopy /q /s /e ^
  "%KOKORO_PIPER_DIR%\google3\third_party\jsoncpp" ^
  "%KOKORO_PIPER_DIR%\google3\third_party\binaryninja_api\third_party\jsoncpp\"

pushd "%OUT_DIR%"
cmake "%SRC_DIR%/binexport" ^
  -G "Ninja" ^
  -DFETCHCONTENT_FULLY_DISCONNECTED=ON ^
  "-DFETCHCONTENT_SOURCE_DIR_ABSL=%KOKORO_ARTIFACTS_DIR%\git\absl" ^
  "-DFETCHCONTENT_SOURCE_DIR_GOOGLETEST=%KOKORO_ARTIFACTS_DIR%\git\googletest" ^
  "-DFETCHCONTENT_SOURCE_DIR_PROTOBUF=%KOKORO_ARTIFACTS_DIR%\git\protobuf" ^
  "-DFETCHCONTENT_SOURCE_DIR_BINARYNINJAAPI=%KOKORO_PIPER_DIR%\google3\third_party\binaryninja_api" ^
  -DCMAKE_BUILD_TYPE=Release ^
  "-DCMAKE_INSTALL_PREFIX=%OUT_DIR%" ^
  "-DBOOST_ROOT=%KOKORO_PIPER_DIR%\google3\third_party\boost\do_not_include_from_google3_only_third_party\boost" ^
  "-DIdaSdk_ROOT_DIR=%KOKORO_PIPER_DIR%\google3\third_party\idasdk" ^
  -DBUILD_TESTING=OFF || exit /b
cmake --build . --config Release || exit /b
ctest --build-config Release --output-on-failure -R "^[A-Z]" || exit /b
cmake --install . --config Release --strip || exit /b
popd

if "%1" neq "release" exit /b %ERRORLEVEL%

:: Release build, code sign the artifacts
echo Code signing artifacts...

set ARTIFACTS=^
  "%OUT_DIR%\binexport-prefix\binexport*.dll" ^
  "%OUT_DIR%\binexport-prefix\binexport2dump.exe"

%SIGNTOOL% sign /v /tr http://timestamp.digicert.com /n "Google" /a /fd sha256 ^
  /td sha256 %ARTIFACTS%
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

%SIGNTOOL% verify /pa /all %ARTIFACTS%
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%
