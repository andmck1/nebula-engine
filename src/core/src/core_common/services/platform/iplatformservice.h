#pragma once

#include "core_common/services/platform/iinputservice.h"
#include "namespaces.h"
#include <memory>

NS_NEBULA_CORE_BEGIN
class IPlatformService
{
    public:
    virtual ~IPlatformService() = default;

    virtual void createWindow() = 0;
    virtual void pollEvents() = 0;
    virtual void shutdown() = 0;
    virtual bool isExitRequested() = 0;

    std::unique_ptr<IInputService> input;
};
NS_NEBULA_CORE_END
