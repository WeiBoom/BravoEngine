#include "pch.h"

#include "Bravo/Application.h"
#include "Bravo/Events/ApplicationEvent.h"
#include "Bravo/Core/Log.h"

namespace Bravo
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		BRAVO_TRACE(e.ToString());

		while (true);
	}
}
