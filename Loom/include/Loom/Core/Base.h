#pragma once

#include <memory>
#include <utility>

#define BIT(x) (1 << (x))

#define LOOM_BIND_EVENT_FN(fn) \
    [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Loom
{

} // namespace Loom
