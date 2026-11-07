#pragma once

#include "core_common/services/platform/iinputservice.h"
#include "core_common/services/platform/iplatformservice.h"
#include "core_common/services/platform/windowglfw.h"

#include <memory>
#include <string>

struct PlatformConfig
{
    std::string window_title = "Nebula Engine";
    uint32_t window_width = 1280;
    uint32_t window_height = 720;
};

class PlatformLinux : public IPlatformService
{
    public:
    PlatformLinux(const PlatformConfig config);
    ~PlatformLinux();

    void createWindow() override;
    void pollEvents() override;
    void shutdown() override;
    bool isExitRequested() override;
    std::unique_ptr<IInputService> input;

    private:
    PlatformConfig config_;
    std::unique_ptr<WindowGLFW> window_;
    // TODO - no way to check this through glfw?
    bool isGLFWInitialised;
};
