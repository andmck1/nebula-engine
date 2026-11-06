#pragma once

#include "core_common/services/logging/iloggerservice.h"
#include "core_common/types/return_codes.h"

#include <memory>
#include <string>

class Application
{
    public:
    bool run();

    private:
    void initLogging();

    std::string name_ = "NebulaEngine";
    std::unique_ptr<ILoggerService> logger_;
};
