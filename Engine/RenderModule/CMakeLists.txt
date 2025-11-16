set(SOURCE
        testfile.h
        testfile.cpp
        )

list(TRANSFORM SOURCE PREPEND "src/")


add_library(RenderModule STATIC ${SOURCE})
target_link_libraries(RenderModule PRIVATE CoreModule)

include_directories(src)

if (STOMP_ENABLE_TESTS)
        set(TESTS
                testfiletest.cpp
        )
        list(TRANSFORM TESTS PREPEND "tests/")
        add_executable(RenderModuleTests ${TESTS})
        add_test(NAME RenderTests COMMAND RenderModuleTests)
        target_link_libraries(RenderModuleTests gtest gtest_main RenderModule)
endif()
