#!/bin/bash

# Stop at first error
set -e

cmake -P ./CMake/setup_vcpkg.cmake

export VCPKG_FEATURE_FLAGS="manifests"
export VCPKG_FORCE_SYSTEM_BINARIES=1

chmod +x "./external/vcpkg/vcpkg"
"./external/vcpkg/vcpkg" install

# Check if Ninja is in PATH
if command -v ninja >/dev/null 2>&1; then
    echo "Ninja is already installed."
else
    # Download and install Ninja for Linux
    echo "Installing Ninja..."
    # Using curl (standard on most systems)
    curl -LO https://github.com/ninja-build/ninja/releases/latest/download/ninja-linux.zip
    
    # Create directory and unzip
    mkdir -p "./external/ninja"
    unzip -o ninja-linux.zip -d "./external/ninja"
    rm ninja-linux.zip
    
    # Make sure the binary is executable
    chmod +x "./external/ninja/ninja"

    # Add to PATH for this session
    export PATH="$PWD/external/ninja:$PATH"
fi

# 7. Configure and Build
cmake -S . -B build -G "Ninja Multi-Config" -DCMAKE_TOOLCHAIN_FILE="./external/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build --config Release