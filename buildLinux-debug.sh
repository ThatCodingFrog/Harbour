#!/bin/bash

# 1. Run initial CMake setup
cmake -P ./CMake/setup_vcpkg.cmake

# 2. Set environment variables (no spaces around '=')
export VCPKG_FEATURE_FLAGS="manifests"

# 3. Run vcpkg (assuming the Linux/macOS binary 'vcpkg' exists there)
"./external/vcpkg/vcpkg" install

# 4. Check if Ninja is in PATH
if command -v ninja >/dev/null 2>&1; then
    echo "Ninja is already installed."
else
    # 5. Download and install Ninja for Linux
    echo "Installing Ninja..."
    # Using curl (standard on most systems)
    curl -LO https://github.com/ninja-build/ninja/releases/latest/download/ninja-linux.zip
    
    # Create directory and unzip
    mkdir -p "./external/ninja"
    unzip -o ninja-linux.zip -d "./external/ninja"
    rm ninja-linux.zip
    
    # Make sure the binary is executable
    chmod +x "./external/ninja/ninja"

    # 6. Add to PATH for this session
    export PATH="$PWD/external/ninja:$PATH"
fi

# 7. Configure and Build
cmake -S . -B build -G "Ninja Multi-Config" -DCMAKE_TOOLCHAIN_FILE="./external/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build --config Debug