#pragma once

#include "namespaces.h"
#include <string>

NS_NEBULA_CORE_BEGIN
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
NS_NEBULA_CORE_END
