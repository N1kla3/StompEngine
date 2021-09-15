//
// Created by kolya on 9/12/2021.
//

#include "totest.h"
#include "iostream"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void my::function()
{
    std::cout << "connected";
}

void my::PrintVersionss()
{
    function();
}

void my::stdout_example()
{
    // create color multi threaded logger
    auto console = spdlog::stdout_color_mt("console");
    auto err_logger = spdlog::stderr_color_mt("stderr");
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}

void my::whata() {
#if ENGINE_MAJOR_VERSION == 0
    std::cout << ENGINE_MAJOR_VERSION;
#endif
}

