#include "core_common/services/platform/linux.h"
#include "core_common/services/platform/inputglfw.h"
#include "core_common/services/servicelocator.h"

#include <GLFW/glfw3.h>

NS_NEBULA_CORE_BEGIN
PlatformLinux::PlatformLinux(const PlatformConfig config)
{
    config_ = config;
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);

    if (glfwInit())
    {
        isGLFWInitialised = true;
        ServiceLocator::GetLoggingService()->debug(
            "GLFW initialised successfully"
        );
        return;
    }
    ServiceLocator::GetLoggingService()->error("GLFW failed to initialise");
}

PlatformLinux::~PlatformLinux()
{
    shutdown();
}

void PlatformLinux::createWindow()
{
    if (!isGLFWInitialised)
    {
        ServiceLocator::GetLoggingService()->error("Platform not initialised");
        return;
    }

    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window_ = std::make_unique<WindowGLFW>(
        config_.window_width, config_.window_height,
        config_.window_title.c_str()
    );

    if (!window_->isInitialised())
    {
        ServiceLocator::GetLoggingService()->error("Window creation failed");
        return;
    }
    input = std::make_unique<InputGLFW>();
    glfwSetKeyCallback(window_->window, InputGLFW::keyCallback);

    glfwShowWindow(window_->window);
    ServiceLocator::GetLoggingService()->debug("Window created and shown");
}

void PlatformLinux::pollEvents()
{
    glfwPollEvents();
}

void PlatformLinux::shutdown()
{
    ServiceLocator::GetLoggingService()->debug("Platform shutting down");
    if (window_)
        window_->shutdown();
    glfwTerminate();
    ServiceLocator::GetLoggingService()->debug("Platform shut down complete");
}

bool PlatformLinux::isExitRequested()
{
    if (glfwWindowShouldClose(window_->window))
        return true;
    if (input->isKeyPressed(KeyCode::Escape))
        return true;
    return false;
}
NS_NEBULA_CORE_END
