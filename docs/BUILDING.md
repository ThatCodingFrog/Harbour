# Building Harbour Ports

## Prerequisites on all platforms
- C++ compiler
- Git
- CMake
- vcpkg

## Windows

- Configure CMake (should automatically install vcpkg dependencies)
    - I usually use Ninja for configuring, if you want to do that just add `-G Ninja` to the command
    - _(if vcpkg dependencies do not automatically download, run vcpkg install in your project root, then delete the build folder and reconfigure)_

```powershell
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
```
    

- Build Harbour Ports
```powershell
cmake --build build
```
- The executable will be found at `build/Harbour.exe`

## Linux
- Ensure all dependencies are installed (Ubuntu)
```bash
sudo apt-get install -y \
            autoconf \
            autoconf-archive \
            automake \
            libtool \
            libltdl-dev \
            build-essential \
            curl \
            zip \
            unzip \
            tar \
            pkg-config \
            libssl-dev \
            libx11-dev \
            libgl1-mesa-dev
```
- Ensure vcpkg dependencies are installed
```bash
./path/to/vcpkg install
```

- Configure CMake
```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

- Build Harbour Ports
```bash
cmake --build build
```
- The executable will be found at `build/Harbour`


## macOS
_note: documentation is still undergoing for macOS_
- Ensure cURL is installed
```
brew install curl
```

- Ensure vcpkg dependencies are installed
```
./path/to/vcpkg install
```

- Configure CMake
```
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

- Build Harbour Ports
```
cmake --build build
```

For additional help, please refer to the [workflow](../.github/workflows/build.yaml) and the section for your specific platform.
