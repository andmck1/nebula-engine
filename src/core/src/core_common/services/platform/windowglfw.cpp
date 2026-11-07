#include "core_common/services/platform/windowglfw.h"
#include "core_common/services/servicelocator.h"
#include <format>

WindowGLFW::WindowGLFW(uint32_t width, uint32_t height, const char *title)
{
    ServiceLocator::GetLoggingService()->debug(
        std::format("Creating GLFW window: {}x{} '{}'", width, height, title)
    );
    window = glfwCreateWindow(
        static_cast<int>(width), static_cast<int>(height), title, nullptr,
        nullptr
    );
    if (!window)
    {
        ServiceLocator::GetLoggingService()->error("Failed to create window");
        return;
    }

    ServiceLocator::GetLoggingService()->debug("GLFW window created");
    glfwSetWindowCloseCallback(window, closeCallback);
    glfwMakeContextCurrent(window);
}

WindowGLFW::~WindowGLFW()
{
    shutdown();
}

const bool WindowGLFW::isInitialised()
{
    return !(window == nullptr);
}

void WindowGLFW::shutdown()
{
    if (window)
    {
        ServiceLocator::GetLoggingService()->debug("Destroying GLFW window");
        glfwDestroyWindow(window);
        window = nullptr;
    }
}

void WindowGLFW::closeCallback(GLFWwindow *window)
{
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
