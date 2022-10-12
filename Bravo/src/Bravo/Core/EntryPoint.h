#pragma once

#include "pch.h"


#ifdef BRAVO_PLATFORM_WINDOWS

extern Bravo::Application* Bravo::CreateApplication();

int main(int args, char** argv)
{
	// log system
	Bravo::Log::Init();
	BRAVO_CORE_INFO("spdlog system init!");

	// init application
	auto app = Bravo::CreateApplication();
	app->Run();
	delete app;

}

#endif