#pragma once

#include "core_common/services/logging/iloggerservice.h"
#include "core_common/services/platform/iplatformservice.h"
#include "core_common/types/return_codes.h"

#include <memory>
#include <string>

class Application
{
    public:
    bool run();

    private:
    void initLogging();
    void initPlatform();

    std::string name_ = "NebulaEngine";

    // services
    std::unique_ptr<ILoggerService> logger_;
    std::unique_ptr<IPlatformService> platform_;
};
