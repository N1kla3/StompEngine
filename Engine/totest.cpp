//
// Created by kolya on 9/12/2021.
//

#include "totest.h"
#include "iostream"

void my::function()
{
    std::cout << "connected";
}

void my::PrintVersionss()
{
    function();
}

void my::whata() {
#if ENGINE_MAJOR_VERSION == 0
    std::cout << ENGINE_MAJOR_VERSION;
#endif
}

