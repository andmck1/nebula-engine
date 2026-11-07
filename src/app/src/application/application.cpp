#include "application.h"

#include "core_common/services/logging/iloggerservice.h"
#include "core_common/services/logging/consolelogger.h"
#include "core_common/services/platform/linux.h"
#include "core_common/services/servicelocator.h"

Nebula::Core::ReturnCode Application::run(int argc, char *argv[])
{
    processCLI(argc, argv);

    initLogging();
    initPlatform();

    logger_->info("Started Application");
    while (!platform_->isExitRequested())
    {
        platform_->pollEvents();
    }
    return Nebula::Core::ReturnCode::SUCCESS;
}

void Application::processCLI(int argc, char *argv[])
{
    CLI::App cli(name_);
    argv = cli.ensure_utf8(argv);

    cli.add_flag("--debug", settings_.isDebugEnabled_);

    cli.parse(argc, argv);
}

void Application::initLogging()
{
    logger_ = std::make_unique<Nebula::Core::ConsoleLogger>(name_);
    if (settings_.isDebugEnabled_)
    {
        logger_->setLevel(Nebula::Core::LoggingLevel::DEBUG);
        logger_->debug("Logging level set to DEBUG");
    }
    else
    {
        logger_->setLevel(Nebula::Core::LoggingLevel::INFO);
        logger_->info("Logging level set to INFO");
    }
    Nebula::Core::ServiceLocator::SetLoggingService(logger_.get());
}

void Application::initPlatform()
{
    Nebula::Core::PlatformConfig config = {
        "Nebula Engine Demo",
        1280,
        720,
    };
    platform_ = std::make_unique<Nebula::Core::PlatformLinux>(config);
    platform_->createWindow();
    Nebula::Core::ServiceLocator::SetPlatformService(platform_.get());
    Nebula::Core::ServiceLocator::SetInputService(platform_->input.get());
}
