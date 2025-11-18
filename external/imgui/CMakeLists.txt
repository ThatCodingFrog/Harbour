# Minimal CMakeLists for ImGui
cmake_minimum_required(VERSION 3.16)

# Create a static library target for ImGui
add_library(imgui
    imgui.cpp
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_widgets.cpp
    imgui_tables.cpp
    misc/freetype/imgui_freetype.cpp
    backends/imgui_impl_sdl2.cpp
    backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backends
    ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include/SDL2
)


