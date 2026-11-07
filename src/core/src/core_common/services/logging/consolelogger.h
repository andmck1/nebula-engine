#pragma once

#include "namespaces.h"
#include "core_common/services/logging/iloggerservice.h"

#include <memory>
#include <spdlog/spdlog.h>
#include <string>
#include <unordered_map>

NS_NEBULA_CORE_BEGIN
static inline std::unordered_map<LoggingLevel, spdlog::level::level_enum>
    spdlogLevelMap = {
        {LoggingLevel::DEBUG, spdlog::level::level_enum::debug},
        {LoggingLevel::INFO, spdlog::level::level_enum::info},
        {LoggingLevel::WARNING, spdlog::level::level_enum::warn},
        {LoggingLevel::ERROR, spdlog::level::level_enum::err},
};

class ConsoleLogger : public ILoggerService
{
    public:
    ConsoleLogger(std::string loggerName);

    void debug(std::string message) override;
    void info(std::string message) override;
    void warning(std::string message) override;
    void error(std::string message) override;

    void setLevel(LoggingLevel level) override;

    private:
    std::string loggerName_;
    std::unique_ptr<spdlog::logger> logger_;
};
NS_NEBULA_CORE_END
