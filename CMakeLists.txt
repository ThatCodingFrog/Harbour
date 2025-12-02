# Root CMakeLists.txt
# Assisted by ChatGPT, because I'm a beginner to CMake
# Also assisted by Search Assist

cmake_minimum_required(VERSION 3.16)

include(CMake/setup_vcpkg.cmake)

# Now force toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_TOOLCHAIN_FILE}" CACHE STRING "" FORCE)
endif()

project(Harbour VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)

add_executable(Harbour
    Harbour/src/main.cpp
    Harbour/src/App.cpp
    Harbour/src/GameCard.cpp
    Harbour/src/utils/FileManager.cpp 
    Harbour/include/MenuScreen.h
    Harbour/src/MenuScreen.cpp
    Harbour/include/utils/LoadImage.h
    Harbour/src/utils/LoadImage.cpp
)

target_include_directories(Harbour PRIVATE 
    Harbour/include
    external
)

add_subdirectory(external/imgui)

target_link_libraries(imgui PRIVATE freetype)

target_link_libraries(Harbour PRIVATE SDL2::SDL2 glad::glad)
target_link_libraries(Harbour PRIVATE imgui)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}>/library
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/Harbour/allGames.json
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/library/allGames.json
)


add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
