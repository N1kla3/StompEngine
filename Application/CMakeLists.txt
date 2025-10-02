set(SOURCE
        main.cpp
        )

add_executable(StompEngine ${SOURCE})

target_link_libraries(StompEngine LogModule)
