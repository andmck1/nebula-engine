#pragma once

#include "namespaces.h"
#include <string>

NS_NEBULA_CORE_BEGIN
enum LoggingLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

class ILoggerService
{
    public:
    virtual ~ILoggerService() = default;

    virtual void debug(std::string message) = 0;
    virtual void info(std::string message) = 0;
    virtual void warning(std::string message) = 0;
    virtual void error(std::string message) = 0;

    virtual LoggingLevel getLevel() = 0;
    virtual void setLevel(LoggingLevel level) = 0;
    
    protected:
    LoggingLevel level_ = LoggingLevel::INFO;
};
NS_NEBULA_CORE_END
