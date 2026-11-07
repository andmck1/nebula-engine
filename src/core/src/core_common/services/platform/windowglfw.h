#pragma once

#include "namespaces.h"
#include <GLFW/glfw3.h>

NS_NEBULA_CORE_BEGIN
class WindowGLFW
{
    public:
    WindowGLFW(uint32_t width, uint32_t height, const char *title);
    ~WindowGLFW();

    const bool isInitialised();
    void shutdown();

    GLFWwindow *window;

    private:
    static void closeCallback(GLFWwindow *);
};
NS_NEBULA_CORE_END
