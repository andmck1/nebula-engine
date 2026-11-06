#pragma once

#include "core_common/services/logging/iloggerservice.h"

#include <memory>
#include <spdlog/spdlog.h>
#include <string>

class ConsoleLogger : public ILoggerService
{
    public:
    ConsoleLogger(std::string loggerName);

    void debug(std::string message);
    void info(std::string message);
    void warning(std::string message);
    void error(std::string message);

    private:
    std::string loggerName_;
    std::unique_ptr<spdlog::logger> logger_;
};
