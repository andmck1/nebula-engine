#pragma once

#include "core_common/services/logging/iloggerservice.h"

#include <typeindex>
#include <unordered_map>

class ServiceLocator
{
    public:
    static ILoggerService *GetLoggingService();
    static void SetLoggingService(ILoggerService *loggingService);

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
