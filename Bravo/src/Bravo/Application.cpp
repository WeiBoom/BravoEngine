#include "pch.h"

#include "Bravo/Application.h"
#include "Bravo/Events/ApplicationEvent.h"
#include "Bravo/Core/Log.h"

#include <GLFW/glfw3.h>

namespace Bravo
{
	Application::Application()
	{
		m_Window = Window::Create();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
