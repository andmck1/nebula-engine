#pragma once

#include <string>
class ILoggerService
{
    public:
    virtual ~ILoggerService() = default;

    virtual void debug(std::string message) = 0;
    virtual void info(std::string message) = 0;
    virtual void warning(std::string message) = 0;
    virtual void error(std::string message) = 0;
};
