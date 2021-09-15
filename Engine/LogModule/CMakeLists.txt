set(SOURCE
        totest.h
        totest.cpp
        )

set(TESTS
        LogModuleTest.cpp
        )

list(TRANSFORM TESTS PREPEND "tests/")
list(TRANSFORM SOURCE PREPEND "src/")

add_library(LogModule SHARED ${SOURCE})
add_executable(LogModuleTests ${TESTS})
add_test(NAME Logs COMMAND LogModuleTests)

target_link_libraries(LogModule PRIVATE spdlog::spdlog)
target_link_libraries(LogModuleTests gtest gtest_main LogModule)
#TODO: macros for module naming and auto detection of files in folder