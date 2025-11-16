if (STOMP_ENABLE_TESTS)
        enable_testing()
endif()

add_subdirectory(CoreModule)
add_subdirectory(RenderModule)

add_executable(StompEngine main.cpp)
target_link_libraries(StompEngine CoreModule RenderModule)

