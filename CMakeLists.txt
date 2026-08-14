# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(Harbour VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(LibArchive REQUIRED)
find_package(cpr REQUIRED)


add_executable(Harbour
    Harbour/src/main.cpp
    Harbour/src/App.cpp
    Harbour/src/GameCard.cpp
    Harbour/src/utils/FileManager.cpp
    Harbour/src/MenuScreen.cpp
    Harbour/src/utils/LoadImage.cpp
    Harbour/src/utils/NetworkManager.cpp
    Harbour/src/utils/DownloadManager.cpp
    Harbour/src/utils/LibraryManager.cpp
)

target_include_directories(Harbour PRIVATE 
    Harbour/include
    external
)

add_subdirectory(external/imgui)

target_link_libraries(imgui PRIVATE freetype)

target_link_libraries(Harbour PRIVATE SDL3::SDL3 glad::glad LibArchive::LibArchive)

target_link_libraries(Harbour PRIVATE imgui)
target_link_libraries(Harbour PRIVATE cpr::cpr)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
