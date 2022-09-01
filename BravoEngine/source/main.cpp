#include "define.h"
#include "Application.h"
#include "utils/Log.h"

int main()
{
	Bravo::Log::Init();
	// init application
	std::string app_name = "Bravo Engine";
	auto app = std::make_unique<Bravo::Application>(app_name);
	Bravo::Log::GetCoreLogger()->info("initialize");
	BRAVO_CORE_INFO("{0} initialize success", app_name);
	// tick render
	app->Loop();


}
