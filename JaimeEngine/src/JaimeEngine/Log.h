#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace JaimeEngine
{
	class JE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define JE_CORE_TRACE(...)    ::JaimeEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JE_CORE_DEBUG(...)    ::JaimeEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define JE_CORE_INFO(...)     ::JaimeEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JE_CORE_WARN(...)     ::JaimeEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JE_CORE_ERROR(...)    ::JaimeEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JE_CORE_CRITICAL(...) ::JaimeEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)


//Client log macros
#define JE_TRACE(...)    ::JaimeEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JE_DEBUG(...)    ::JaimeEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define JE_INFO(...)     ::JaimeEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define JE_WARN(...)     ::JaimeEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JE_ERROR(...)    ::JaimeEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define JE_CRITICAL(...) ::JaimeEngine::Log::GetClientLogger()->critical(__VA_ARGS__)