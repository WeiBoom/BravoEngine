#include "Application.h"

namespace Bravo
{
	Application::Application(const std::string& app_name)
	{
		m_window = std::make_unique<Bravo::GLWindow>();
		m_window->init(800, 600, "Bravo Engine");
	}

	void Application::Loop()
	{
		m_window->PrepareData();
		while (m_window->is_running())
		{
			m_window->render();
		}
	}
}


