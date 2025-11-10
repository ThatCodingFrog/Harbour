
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

add_executable(Harbour src/main.cpp)

add_subdirectory(external/imgui)

target_link_libraries(imgui PRIVATE freetype)

get_directory_property(GLOBAL_DEFS COMPILE_DEFINITIONS)
message(STATUS ">>> Global compile definitions: ${GLOBAL_DEFS}")

get_target_property(IMGUI_DEFS imgui COMPILE_DEFINITIONS)
message(STATUS ">>> ImGui compile definitions: ${IMGUI_DEFS}")


target_link_libraries(Harbour PRIVATE SDL2::SDL2 glad::glad)
target_link_libraries(Harbour PRIVATE imgui)

get_target_property(IMGUI_SOURCES imgui SOURCES)
message(STATUS ">>> ImGui source files: ${IMGUI_SOURCES}")