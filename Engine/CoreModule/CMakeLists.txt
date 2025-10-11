set(SOURCE
        Containers/Vector.h
        Log/Logs.cpp
        Log/Logs.h
        Log/totest.h
        Log/totest.cpp
        Text/String.h
        )


list(TRANSFORM SOURCE PREPEND "src/")

add_subdirectory(spdlog)

add_library(CoreModule STATIC ${SOURCE})
target_link_libraries(CoreModule PUBLIC spdlog::spdlog)

if (STOMP_ENABLE_TESTS)
        set(TESTS
                LogsTest.cpp
        )
        list(TRANSFORM TESTS PREPEND "tests/")
        add_executable(CoreModuleTests ${TESTS})
        add_test(NAME CoreTests COMMAND CoreModuleTests)
        target_link_libraries(CoreModuleTests gtest gtest_main CoreModule)
endif()

