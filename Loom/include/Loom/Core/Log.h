#pragma once
#include "Loom/Core/Base.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Loom
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
} // namespace Loom

#define LOOM_CORE_TRACE(...)    ::Loom::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOOM_CORE_INFO(...)     ::Loom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOOM_CORE_WARN(...)     ::Loom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOOM_CORE_ERROR(...)    ::Loom::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOOM_CORE_CRITICAL(...) ::Loom::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define LOOM_TRACE(...)    ::Loom::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOOM_INFO(...)     ::Loom::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOOM_WARN(...)     ::Loom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOOM_ERROR(...)    ::Loom::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOOM_CRITICAL(...) ::Loom::Log::GetClientLogger()->critical(__VA_ARGS__)
