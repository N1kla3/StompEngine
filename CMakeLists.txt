cmake_minimum_required(VERSION 3.17)

set(ENGINE_MAJOR_VERSION 0)
set(ENGINE_MINOR_VERSION 0)
set(ENGINE_PATCH_VERSION 1)

set(PROJECT_NAME StompEngine)
project(${PROJECT_NAME} VERSION ${ENGINE_MAJOR_VERSION}.${ENGINE_MINOR_VERSION}.${ENGINE_PATCH_VERSION})

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/Engine)

include(ProjectOptions.cmake)
stomp_setup_options()
stomp_local_options()

add_compile_options()
add_compile_definitions(ENABLE_TESTING=${ENABLE_TESTING}
        ENGINE_MAJOR_VERSION=${ENGINE_MAJOR_VERSION}
        ENGINE_MINOR_VERSION=${ENGINE_MINOR_VERSION}
        ENGINE_PATCH_VERSION=${ENGINE_PATCH_VERSION}
        )

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

add_subdirectory(Engine)
add_subdirectory(Tools)
add_subdirectory(Editor)

if(STOMP_ENABLE_TESTS)
        # for all tests use googletest
        include(CTest)
        enable_testing()
        add_subdirectory(googletest)
endif()

# TODO: find package

