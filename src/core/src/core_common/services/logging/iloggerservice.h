#pragma once

#include <string>

enum LoggingLevel
{
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
};

class ILoggerService
{
    public:
    virtual ~ILoggerService() = default;

    virtual void debug(std::string message) = 0;
    virtual void info(std::string message) = 0;
    virtual void warning(std::string message) = 0;
    virtual void error(std::string message) = 0;

    virtual void setLevel(LoggingLevel level) = 0;
};
