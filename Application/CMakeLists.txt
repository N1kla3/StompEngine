set(SOURCE
        main.cpp
        )

add_executable(Game ${SOURCE})

target_link_libraries(Game LogModule)
