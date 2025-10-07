set(SOURCE
        totest.h
        totest.cpp
        )


list(TRANSFORM SOURCE PREPEND "src/")

add_subdirectory(spdlog)

add_library(LogModule STATIC ${SOURCE})
target_link_libraries(LogModule PUBLIC spdlog::spdlog)

if (STOMP_ENABLE_TESTS)
        set(TESTS
                LogModuleTest.cpp
        )
        list(TRANSFORM TESTS PREPEND "tests/")
        add_executable(LogModuleTests ${TESTS})
        add_test(NAME Logs COMMAND LogModuleTests)
        target_link_libraries(LogModuleTests gtest gtest_main LogModule)
endif()

#TODO: macros for module naming and auto detection of files in folder
