#pragma once

#pragma warning(push)
#pragma warning(disable : 4459)
#include <spdlog/sinks/basic_file_sink.h>
#include "CoreModule/src/Text/String.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#pragma warning(pop)

namespace omp
{
    [[nodiscard]] bool RegisterLog(const omp::String& name);

} // namespace omp

#define MAKE_LOG_CATEGORY(CategoryName)                                                                                \
    class CategoryName                                                                                                 \
    {                                                                                                                  \
    public:                                                                                                            \
        CategoryName()                                                                                                 \
        {                                                                                                              \
            static bool once = omp::RegisterLog(getCategoryName());                                                    \
        }                                                                                                              \
        omp::String getCategoryName() const                                                                            \
        {                                                                                                              \
            return #CategoryName;                                                                                      \
        }                                                                                                              \
    }


// Logs
#define INFO(Category, ...) spdlog::get(Category().getCategoryName())->info(__VA_ARGS__)
#define WARN(Category, ...) spdlog::get(Category().getCategoryName())->warn(__VA_ARGS__)
#define ERROR(Category, ...) spdlog::get(Category().getCategoryName())->error(__VA_ARGS__)

#ifdef _MSC_VER
#define VINFO(Category, Message, ...)                                                                                  \
    spdlog::get(Category().getCategoryName())->info("{} " Message, __FUNCTION__, __VA_ARGS__)
#define VWARN(Category, Message, ...)                                                                                  \
    spdlog::get(Category().getCategoryName())->warn("{} " Message, __FUNCTION__, __VA_ARGS__)
#define VERROR(Category, Message, ...)                                                                                 \
    spdlog::get(Category().getCategoryName())->error("{} " Message, __FUNCTION__, __VA_ARGS__)
#else
#define VINFO(Category, Message, ...)                                                                                  \
    spdlog::get(Category().getCategoryName())->info("{} " Message, __FUNCTION__ __VA_OPT__(, ) __VA_ARGS__)
#define VWARN(Category, Message, ...)                                                                                  \
    spdlog::get(Category().getCategoryName())->warn("{} " Message, __FUNCTION__ __VA_OPT__(, ) __VA_ARGS__)
#define VERROR(Category, Message, ...)                                                                                 \
    spdlog::get(Category().getCategoryName())->error("{} " Message, __FUNCTION__ __VA_OPT__(, ) __VA_ARGS__)
#endif
