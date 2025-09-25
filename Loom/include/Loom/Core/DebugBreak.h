#pragma once

#include "Loom/Core/PlatformDetection.h"

#ifdef LOOM_DEBUG
#   if defined(LOOM_PLATFORM_WINDOWS)
#       define LOOM_DEBUGBREAK() __debugbreak()
#   elif defined(LOOM_PLATFORM_LINUX)
#       include <signal.h>
#       define LOOM_DEBUGBREAK() raise(SIGTRAP)
#   else
#       error "Platform doesn't support debugbreak yet!"
#   endif
#   define LOOM_ENABLE_ASSERTS
#else
#   define LOOM_DEBUGBREAK()
#endif
