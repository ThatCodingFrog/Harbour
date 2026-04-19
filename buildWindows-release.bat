cmake -P ./CMake/setup_vcpkg.cmake
set VCPKG_FEATURE_FLAGS=manifests
"./external/vcpkg/vcpkg.exe" install


@echo off
:: Check if Ninja is in PATH
where /q ninja.exe
if %errorlevel% equ 0 (
    echo Ninja is already installed.
    goto :cmake
)

:: Download and install Ninja
echo Installing Ninja...
powershell -Command "Invoke-WebRequest -Uri 'https://github.com/ninja-build/ninja/releases/latest/download/ninja-win.zip' -OutFile 'ninja-win.zip'"
powershell -Command "Expand-Archive -Path 'ninja-win.zip' -DestinationPath '%cd%\external\ninja' -Force"
del ninja-win.zip

:: Add current directory to PATH for this session
set PATH=%cd%\external\ninja;%PATH%

:cmake
cmake -S . -B build -G "Ninja Multi-Config" -DCMAKE_TOOLCHAIN_FILE="./external/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build --config Release