#include "application.h"

#include "spdlog/spdlog.h"

bool Application::run()
{
    spdlog::info("App started");
    return true;
}
