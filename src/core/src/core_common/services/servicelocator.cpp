#include "core_common/services/servicelocator.h"

ILoggerService *ServiceLocator::GetLoggingService()
{
    return ServiceLocator::get<ILoggerService>();
}

void ServiceLocator::SetLoggingService(ILoggerService *loggingService)
{
    services_[typeid(ILoggerService)] = loggingService;
}
