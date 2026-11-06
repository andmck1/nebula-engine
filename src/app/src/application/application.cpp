#include "application.h"

#include "core_common/services/logging/iloggerservice.h"
#include "core_common/services/logging/consolelogger.h"
#include "core_common/services/servicelocator.h"

bool Application::run()
{
    initLogging();

    logger_->info("Started Application");
    return true;
}

void Application::initLogging()
{
    logger_ = std::make_unique<ConsoleLogger>(name_);
    ServiceLocator::SetLoggingService(logger_.get());
}
