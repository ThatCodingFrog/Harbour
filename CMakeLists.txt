# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(Harbour VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(LibArchive REQUIRED)
find_package(cpr REQUIRED)

# include(FetchContent)

# FetchContent_Declare(
#     cpr
#     GIT_REPOSITORY https://github.com/libcpr/cpr.git
#     GIT_TAG 1.14.2
# )

# FetchContent_MakeAvailable(cpr)


add_executable(Harbour
    Harbour/src/main.cpp
    Harbour/src/App.cpp
    Harbour/src/GameCard.cpp
    Harbour/src/utils/FileManager.cpp
    Harbour/src/MenuScreen.cpp
    Harbour/src/utils/LoadImage.cpp
    Harbour/src/utils/NetworkManager.cpp
    Harbour/src/utils/DownloadManager.cpp
)

target_include_directories(Harbour PRIVATE 
    Harbour/include
    external
)

add_subdirectory(external/imgui)

target_link_libraries(imgui PRIVATE freetype)

target_link_libraries(Harbour PRIVATE SDL2::SDL2 glad::glad LibArchive::LibArchive)

target_link_libraries(Harbour PRIVATE imgui)
target_link_libraries(Harbour PRIVATE cpr::cpr)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
