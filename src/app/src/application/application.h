#pragma once

#include "core_common/services/logging/iloggerservice.h"
#include "core_common/services/platform/iplatformservice.h"
#include "core_common/types/return_codes.h"

#include <CLI/CLI.hpp>

#include <memory>
#include <string>

struct ApplicationSettings
{
    bool isDebugEnabled_ = false;
};

class Application
{
    public:
    Nebula::Core::ReturnCode run(int argc, char *argv[]);

    private:
    void processCLI(int argc, char *argv[]);
    void initLogging();
    void initPlatform();

    ApplicationSettings settings_{};

    std::string name_ = "NebulaEngine";

    // services
    std::unique_ptr<Nebula::Core::ILoggerService> logger_;
    std::unique_ptr<Nebula::Core::IPlatformService> platform_;
};
