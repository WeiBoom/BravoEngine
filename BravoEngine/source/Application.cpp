#include "Application.h"

namespace Bravo
{
	Application::Application(const std::string& app_name)
	{
		m_window = std::make_unique<Bravo::GLWindow>();
		m_window->Init(800, 600, app_name);
		//BRAVO_CORE_INFO("application ", app_name, "  initialize success !");
	}

	void Application::Loop()
	{
		m_window->PrepareData();
		while (m_window->IsRunning())
		{
			m_window->Render();
		}
	}
}


