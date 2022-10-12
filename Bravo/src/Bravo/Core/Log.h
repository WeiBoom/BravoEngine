#pragma once

#include "Bravo/Core/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Bravo
{
	class BRAVO_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private :
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// engine log marcors
#define BRAVO_CORE_TRACE(...)	::Bravo::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define BRAVO_CORE_INFO(...)	::Bravo::Log::GetCoreLogger()->info(__VA_ARGS__);
#define BRAVO_CORE_WARN(...)	::Bravo::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define BRAVO_CORE_ERROR(...)	::Bravo::Log::GetCoreLogger()->error(__VA_ARGS__);
#define BRAVO_CORE_FATAL(...)	::Bravo::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// game log macors
#define BRAVO_TRACE(...)		::Bravo::Log::GetClientLogger()->trace(__VA_ARGS__);
#define BRAVO_INFO(...)			::Bravo::Log::GetClientLogger()->info(__VA_ARGS__);
#define BRAVO_WARN(...)			::Bravo::Log::GetClientLogger()->warn(__VA_ARGS__);
#define BRAVO_ERROR(...)		::Bravo::Log::GetClientLogger()->error(__VA_ARGS__);
#define BRAVO_FATAL(...)		::Bravo::Log::GetClientLogger()->fatal(__VA_ARGS__);
