#include "Log.h"
//#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bravo
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		// engine log
		s_CoreLogger = spdlog::stdout_color_mt("BRAVO"); //std::make_shared<spdlog::sinks::stdout_color_sink_mt>("BRAVO");
		s_CoreLogger->set_level(spdlog::level::trace);
		// game log
		s_ClientLogger = spdlog::stdout_color_mt("GAME");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}