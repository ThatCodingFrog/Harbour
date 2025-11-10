# Created by ChatGPT

# --- CMake/setup_vcpkg.cmake ---
cmake_minimum_required(VERSION 3.16)

# Directory where vcpkg should live
set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")

# If vcpkg folder doesn't exist, clone and bootstrap it
if(NOT EXISTS "${VCPKG_ROOT}/vcpkg.exe")
    message(STATUS "vcpkg not found — cloning into external/vcpkg...")

    # Clone vcpkg
    execute_process(
        COMMAND git clone https://github.com/microsoft/vcpkg.git "${VCPKG_ROOT}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
        RESULT_VARIABLE GIT_CLONE_RESULT
    )

    if(NOT GIT_CLONE_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to clone vcpkg. Please check your network connection or git setup.")
    endif()

    # Bootstrap vcpkg (this builds the vcpkg.exe or vcpkg binary)
    message(STATUS "Bootstrapping vcpkg...")
    if(WIN32)
        execute_process(COMMAND "${VCPKG_ROOT}/bootstrap-vcpkg.bat"
                        WORKING_DIRECTORY "${VCPKG_ROOT}"
                        RESULT_VARIABLE BOOTSTRAP_RESULT)
    else()
        execute_process(COMMAND "${VCPKG_ROOT}/bootstrap-vcpkg.sh"
                        WORKING_DIRECTORY "${VCPKG_ROOT}"
                        RESULT_VARIABLE BOOTSTRAP_RESULT)
    endif()

    if(NOT BOOTSTRAP_RESULT EQUAL 0)
        message(FATAL_ERROR "vcpkg bootstrap failed.")
    endif()
else()
    message(STATUS "vcpkg found at ${VCPKG_ROOT}")
endif()

# Export the path to the toolchain file so the parent CMakeLists can include it
set(VCPKG_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" PARENT_SCOPE)
