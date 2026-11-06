#pragma once

#include "GLFW/glfw3.h"
#include <cstdint>
#include <unordered_map>

enum class KeyCode : int32_t
{
    Escape = 256,
};

class InputGLFW
{
    public:
    InputGLFW();
    ~InputGLFW();

    bool isKeyPressed(KeyCode key);

    static void keyCallback(GLFWwindow *, int, int, int, int);

    private:
    static inline InputGLFW *instance_;
    std::unordered_map<KeyCode, bool> keyStates_ = {};

};
