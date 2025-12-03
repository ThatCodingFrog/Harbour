# Building Harbour of Harkinian

## Prerequisites
- C++ compiler
- Git
- CMake

## Windows

Powershell instructions

```powershell
# In the root folder, i.e. Harbour/, run:

cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="external/vcpkg/scripts/buildsystems/vcpkg.cmake"

# Then to build a debug build, run
cmake --build build
```

## Linux
I only did a Linux build once, and in Github Codespaces, and even then I was unable to test it fully.
If someone else has a real Linux machine (or a fuller VM than GH Codespaces) and could test build this, that would be great.

## MacOS
Currently unknown, documentation will be added when verified.