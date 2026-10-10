set(CPACK_PACKAGE_NAME "Harbour-Ports")
set(CPACK_PACKAGE_VENDOR "Harbour Ports Team")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A cross-platform launcher and updater for console game PC ports")
set(CPACK_PACKAGE_VERSION "v0.5.0")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_EXECUTABLES "Harbour" "Harbour Ports")

install(TARGETS Harbour
    RUNTIME_DEPENDENCY_SET HarbourDeps
    RUNTIME DESTINATION .
    BUNDLE DESTINATION .
)

if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    install(DIRECTORY "${CMAKE_SOURCE_DIR}/assets/" DESTINATION "assets")
endif()

if(WIN32)
    install(RUNTIME_DEPENDENCY_SET HarbourDeps
        DESTINATION .
        DIRECTORIES "${CMAKE_BINARY_DIR}/"

        PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
        POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
    )
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "ZIP")
endif()



include(CPack)
