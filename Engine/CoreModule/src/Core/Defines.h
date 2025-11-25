#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #ifdef STOMP_BUILD_API
        #define STOMP_API __declspec(dllexport)
    #elif defined(STOMP_USE_API)
        #define STOMP_API __declspec(dllimport)
    #else
        #define STOMP_API
    #endif
#else
    #if __GNUC__ >= 4
        #define STOMP_API __attribute__((visibility("default")))
    #else
        #define STOMP_API
    #endif
#endif
