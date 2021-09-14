set(SOURCE
        main.cpp
        )

add_executable(Engine ${SOURCE})

target_link_libraries(Engine LogModule)