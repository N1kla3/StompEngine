if (STOMP_ENABLE_TESTS)
        enable_testing()
endif()

add_subdirectory(LogModule)

add_executable(StompEngine main.cpp)
target_link_libraries(StompEngine LogModule)

