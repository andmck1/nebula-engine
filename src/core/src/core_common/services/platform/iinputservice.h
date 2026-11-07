#pragma once
#include "namespaces.h"
#include <cstdint>

NS_NEBULA_CORE_BEGIN
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
NS_NEBULA_CORE_END
