#include "core_common/services/logging/consolelogger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

ConsoleLogger::ConsoleLogger(std::string loggerName)
{
    loggerName_ = loggerName;
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    logger_ = std::make_unique<spdlog::logger>(loggerName, console_sink);
}

void ConsoleLogger::debug(std::string message)
{
    logger_->debug(message);
}

void ConsoleLogger::info(std::string message)
{
    logger_->info(message);
}

void ConsoleLogger::warning(std::string message)
{
    logger_->warn(message);
}

void ConsoleLogger::error(std::string message)
{
    logger_->error(message);
}
