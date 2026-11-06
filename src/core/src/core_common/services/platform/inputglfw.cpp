#include "core_common/services/platform/inputglfw.h"
#include "core_common/services/servicelocator.h"

InputGLFW::InputGLFW()
{
    // TODO - should input be a service?
    instance_ = this;
    ServiceLocator::GetLoggingService()->info("Input system initialised");
}

InputGLFW::~InputGLFW()
{
}

bool InputGLFW::isKeyPressed(KeyCode keyCode)
{
    auto key_state_iterator = keyStates_.find(static_cast<KeyCode>(keyCode));
    if (key_state_iterator != keyStates_.end())
        return key_state_iterator->second;
    return false;
}

void InputGLFW::keyCallback(GLFWwindow *, int key, int, int action, int)
{
    // TODO - throw up, required as this function static...maybe if this
    // static service then this works better?
    if (!instance_)
        return;

    KeyCode keyCode = static_cast<KeyCode>(key);
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        instance_->keyStates_[keyCode] = true;
    }
    else if (action == GLFW_RELEASE)
    {
        instance_->keyStates_[keyCode] = false;
    }
}
