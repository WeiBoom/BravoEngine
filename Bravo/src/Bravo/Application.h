#pragma once

#include "Bravo/Core/Window.h"
#include "Bravo/Events/ApplicationEvent.h"

namespace Bravo
{
	class BRAVO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		Scope<Window> m_Window;
		bool m_Running = true;
	};

	// this function will define in CLIENT
	Bravo::Application* CreateApplication();
}

