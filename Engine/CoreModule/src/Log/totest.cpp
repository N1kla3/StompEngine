//
// Created by kolya on 9/12/2021.
//

#include "totest.h"
#include "iostream"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

void My::function()
{
    std::cout << "connected";
}

void My::PrintVersionss()
{
    function();
}

void My::stdout_example()
{
    // create color multi threaded logger
    auto console = spdlog::stdout_color_mt("console");
    auto err_logger = spdlog::stderr_color_mt("stderr");
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}

void My::whata()
{
#if ENGINE_MAJOR_VERSION == 0
    std::cout << ENGINE_MAJOR_VERSION;
#endif
}
