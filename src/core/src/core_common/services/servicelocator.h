#pragma once

#include "namespaces.h"
#include "core_common/services/logging/iloggerservice.h"
#include "core_common/services/platform/iplatformservice.h"
#include "core_common/services/platform/iinputservice.h"

#include <typeindex>
#include <unordered_map>

NS_NEBULA_CORE_BEGIN
class ServiceLocator
{
    public:
    static ILoggerService *GetLoggingService();
    static void SetLoggingService(ILoggerService *loggingService);

    static IPlatformService *GetPlatformService();
    static void SetPlatformService(IPlatformService *platformService);

    static IInputService *GetInputService();
    static void SetInputService(IInputService *inputService);

    private:
    // TODO - technically this is restricted to certain types only
    template <typename T> static T *get()
    {
        auto services_iterator = services_.find(std::type_index(typeid(T)));
        if (services_iterator != services_.end())
        {
            return static_cast<T *>(services_iterator->second);
        }
        return nullptr;
    }

    static inline std::unordered_map<std::type_index, void *> services_;
};
NS_NEBULA_CORE_END
