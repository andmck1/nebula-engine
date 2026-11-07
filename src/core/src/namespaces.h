#pragma once

#define NS_NEBULA_BEGIN                                                        \
    namespace Nebula                                                           \
    {
#define NS_NEBULA_END }

#define NS_NEBULA_CORE_BEGIN                                                   \
    NS_NEBULA_BEGIN namespace Core                                             \
    {
#define NS_NEBULA_CORE_END                                                     \
    }                                                                          \
    NS_NEBULA_END
