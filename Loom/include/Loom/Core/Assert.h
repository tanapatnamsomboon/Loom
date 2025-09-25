#pragma once

#include "Loom/Core/Log.h"
#include "Loom/Core/DebugBreak.h"

#ifdef LOOM_ENABLE_ASSERTS
#   define LOOM_INTERNAL_ASSERT_IMPL(type, check, msg, ...)                 \
    {                                                                       \
        if(!(check))                                                        \
        {                                                                   \
            LOOM_##type("Assertion Failed: {0}", msg);                      \
            LOOM_DEBUGBREAK();                                              \
        }                                                                   \
    }
#   define LOOM_INTERNAL_ASSERT_WITH_MSG(type, check, ...)                  \
        LOOM_INTERNAL_ASSERT_IMPL(type, check, __VA_ARGS__)
#   define LOOM_INTERNAL_ASSERT_NO_MSG(type, check)                         \
        LOOM_INTERNAL_ASSERT_IMPL(type, check, "No message")
#   define LOOM_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#   define LOOM_INTERNAL_ASSERT_GET_MACRO(...)                              \
        LOOM_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__,                    \
                                            LOOM_INTERNAL_ASSERT_WITH_MSG,  \
                                            LOOM_INTERNAL_ASSERT_NO_MSG)
#   define LOOM_CORE_ASSERT(...)                                            \
        LOOM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(CORE_ERROR, __VA_ARGS__)
#   define LOOM_ASSERT(...)                                                 \
        LOOM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(ERROR, __VA_ARGS__)
#else
#   define LOOM_CORE_ASSERT(...)
#   define LOOM_ASSERT(...)
#endif
