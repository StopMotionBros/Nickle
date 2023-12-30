#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nickle
{
	class NICKLE_API Log
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

#define NK_CORE_TRACE(...)  ::Nickle::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define NK_CORE_INFO(...)   ::Nickle::Log::GetCoreLogger()->info(__VA_ARGS__);
#define NK_CORE_WARN(...)   ::Nickle::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define NK_CORE_ERROR(...)  ::Nickle::Log::GetCoreLogger()->error(__VA_ARGS__);
#define NK_CORE_FATAL(...)  ::Nickle::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define NK_TRACE(...)       ::Nickle::Log::GetClientLogger()->trace(__VA_ARGS__);
#define NK_INFO(...)        ::Nickle::Log::GetClientLogger()->info(__VA_ARGS__);
#define NK_WARN(...)        ::Nickle::Log::GetClientLogger()->warn(__VA_ARGS__);
#define NK_ERROR(...)       ::Nickle::Log::GetClientLogger()->error(__VA_ARGS__);
#define NK_FATAL(...)       ::Nickle::Log::GetClientLogger()->fatal(__VA_ARGS__);