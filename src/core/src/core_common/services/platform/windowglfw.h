#pragma once

#include <GLFW/glfw3.h>

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
