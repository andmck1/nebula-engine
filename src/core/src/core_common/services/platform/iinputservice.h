#pragma once
#include <cstdint>

enum class KeyCode : int32_t
{
    Escape = 256,
};

class IInputService
{
    public:
    virtual ~IInputService() = default;

    virtual bool isKeyPressed(KeyCode key) = 0;
};
