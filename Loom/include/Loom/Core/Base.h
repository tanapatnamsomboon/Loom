#pragma once

#include <memory>

#define BIT(x) (1 << (x))

#define LOOM_BIND_EVENT_FN(fn) \
    [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Loom
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
} // namespace Loom

#include "Loom/Core/Log.h"
#include "Loom/Core/Assert.h"
