cmake_minimum_required(VERSION 3.16)
project(sorts VERSION 1.0)

add_library(Sorts INTERFACE)

set(CMAKE_CXX_STANDARD 17)

add_library(utils::sorts ALIAS Sorts)

install(DIRECTORY include DESTINATION include)
install(TARGETS Sorts EXPORT SortsConfig)
install(EXPORT SortsConfig NAMESPACE cache:: DESTINATION share/Sorts/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/SortsConfigVersion.cmake"
    VERSION
    ${PROJECT_VERSION}
    COMPATIBILITY
    AnyNewerVersion)

install(FILES "${PROJECT_BINARY_DIR}/SortsConfigVersion.cmake" DESTINATION share/Sorts/cmake)

if(DEBUG)
    if(SANITIZERS)
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address,undefined")
    endif()

    if(TESTING)
        enable_testing()
        add_subdirectory(tests)
    endif()
endif()