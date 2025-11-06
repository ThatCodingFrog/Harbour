cmake_minimum_required(VERSION 3.16)
project(Harbour LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- SDL2 ---
find_package(SDL2 CONFIG REQUIRED)  # If you have SDL2 installed system-wide
# or alternatively, use FetchContent to pull it from GitHub.

# --- ImGui ---
add_subdirectory(external/imgui)

# --- Main executable ---
add_executable(Harbour
    src/main.cpp
    src/App.cpp
    src/UIManager.cpp
)

target_include_directories(Harbour PRIVATE
    ${SDL2_INCLUDE_DIRS}
    external/imgui
)

target_link_libraries(Harbour PRIVATE
    ${SDL2_LIBRARIES}
    imgui
)

if (APPLE)
    target_link_libraries(Harbour PRIVATE "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
elseif (UNIX)
    find_package(OpenGL REQUIRED)
    target_link_libraries(Harbour PRIVATE ${OPENGL_LIBRARIES})
elseif (WIN32)
    target_link_libraries(Harbour PRIVATE opengl32)
endif()
