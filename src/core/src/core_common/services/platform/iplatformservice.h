#pragma once

class IPlatformService
{
    public:
    virtual ~IPlatformService() = default;

    virtual void createWindow() = 0;
    virtual void pollEvents() = 0;
    virtual void shutdown() = 0;
    virtual bool isExitRequested() = 0;
};
