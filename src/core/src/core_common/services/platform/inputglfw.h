#pragma once

#include "GLFW/glfw3.h"
#include "core_common/services/platform/iinputservice.h"
#include <unordered_map>

class InputGLFW : public IInputService
{
    public:
    InputGLFW();
    ~InputGLFW();

    bool isKeyPressed(KeyCode key) override;
    static void keyCallback(
        GLFWwindow *window, int key, int scanecode, int action, int mods
    );

    private:
    static inline InputGLFW *instance_;
    std::unordered_map<KeyCode, bool> keyStates_ = {};
};
