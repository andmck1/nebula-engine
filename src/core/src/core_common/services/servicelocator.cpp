#include "core_common/services/servicelocator.h"

ILoggerService *ServiceLocator::GetLoggingService()
{
    return ServiceLocator::get<ILoggerService>();
}

void ServiceLocator::SetLoggingService(ILoggerService *loggingService)
{
    services_[typeid(ILoggerService)] = loggingService;
}

IPlatformService *ServiceLocator::GetPlatformService()
{
    return ServiceLocator::get<IPlatformService>();
}

void ServiceLocator::SetPlatformService(IPlatformService *platformService)
{
    services_[typeid(IPlatformService)] = platformService;
}
IInputService *ServiceLocator::GetInputService()
{
    return ServiceLocator::get<IInputService>();
}

void ServiceLocator::SetInputService(IInputService *inputService)
{
    services_[typeid(IInputService)] = inputService;
}
