# Root CMakeLists.txt
# Assisted by ChatGPT, because I'm a beginner to CMake

cmake_minimum_required(VERSION 3.16)

include(CMake/setup_vcpkg.cmake)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_TOOLCHAIN_FILE}" CACHE STRING "Vcpkg toolchain file")
endif()

project(Harbour LANGUAGES CXX)

add_compile_definitions(IMGUI_DISABLE_FREETYPE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)

add_executable(Harbour
    Harbour/src/main.cpp
    Harbour/src/App.cpp
)

target_include_directories(Harbour PRIVATE Harbour/include)

add_subdirectory(external/imgui)

target_link_libraries(imgui PRIVATE freetype)

target_link_libraries(Harbour PRIVATE SDL2::SDL2 glad::glad)
target_link_libraries(Harbour PRIVATE imgui)
