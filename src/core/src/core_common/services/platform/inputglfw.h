#pragma once

#include "GLFW/glfw3.h"
#include "core_common/services/platform/iinputservice.h"
#include "namespaces.h"
#include <unordered_map>

NS_NEBULA_CORE_BEGIN
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
NS_NEBULA_CORE_END
