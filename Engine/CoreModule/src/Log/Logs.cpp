#include "Logs.h"
#include "CoreModule/src/Containers/Vector.h"

namespace
{
    omp::Vector<spdlog::sink_ptr> getLoggerSinks()
    {
        omp::Vector<spdlog::sink_ptr> sinks;
        sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt"));
        sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        spdlog::set_pattern("[%D %H:%M:%S %z][thread %t]%^[%n][%l]%v%$");
        return sinks;
    }
} // namespace

bool omp::RegisterLog(const omp::String& name)
{
    static auto sinks = ::getLoggerSinks();
    auto registered_log = std::make_shared<spdlog::logger>(name, begin(sinks), end(sinks));
    spdlog::register_logger(registered_log);
    return true;
}
