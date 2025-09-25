#pragma once

#include "Loom/Core/PlatformDetection.h"

#ifdef LOOM_DEBUG
#   if defined(_MSC_VER)
#       include <intrin.h>
#       define LOOM_DEBUGBREAK() __debugbreak()
#   elif defined(__clang__)
#       if __has_builtin(__builtin_debugtrap)
#           define LOOM_DEBUGBREAK() __builtin_debugtrap()
#       else
#           define LOOM_DEBUGBREAK() __builtin_trap()
#       endif
#   elif defined(__GNUC__)
#       if defined(__i386__) || defined(__x86_64__)
#           define LOOM_DEBUGBREAK() __asm__ volatile("int $3")
#       else
#           define LOOM_DEBUGBREAK() __builtin_trap()
#       endif
#   else
#       include <signal.h>
#       define LOOM_DEBUGBREAK() raise(SIGTRAP)
#   endif
#else
#   define LOOM_DEBUGBREAK()
#endif
