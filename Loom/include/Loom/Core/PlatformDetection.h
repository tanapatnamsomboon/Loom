#pragma once

#if defined(_WIN32) || defined(_WIN64)
#   define LOOM_PLATFORM_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
#   define LOOM_PLATFORM_MACOS
#elif defined(__linux__)
#   defined LOOM_PLATFORM_LINUX
#else
#   error "Loom Engine: Unknown platform!"
#endif
