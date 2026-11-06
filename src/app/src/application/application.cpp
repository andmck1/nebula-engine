#include "application.h"

#include "core_common/services/logging/iloggerservice.h"
#include "core_common/services/logging/consolelogger.h"
#include "core_common/services/platform/linux.h"
#include "core_common/services/servicelocator.h"

bool Application::run()
{
    initLogging();
    initPlatform();

    logger_->info("Started Application");
    while (!platform_->isExitRequested())
    {
        platform_->pollEvents();
    }
    return true;
}

void Application::initLogging()
{
    logger_ = std::make_unique<ConsoleLogger>(name_);
    ServiceLocator::SetLoggingService(logger_.get());
}

void Application::initPlatform()
{
    PlatformConfig config = {
        "Nebula Engine Demo",
        1280,
        720,
    };
    platform_ = std::make_unique<PlatformLinux>(config);
    platform_->createWindow();
}
