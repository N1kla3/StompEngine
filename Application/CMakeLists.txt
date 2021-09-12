set(SOURCE
        main.cpp
        )

add_executable(tests ${SOURCE})

target_link_libraries(tests Engine)