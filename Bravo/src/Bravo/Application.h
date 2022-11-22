#pragma once

#include "Bravo/Core/Window.h"
#include "Bravo/Events/ApplicationEvent.h"

#include "Bravo/Core/LayerStack.h"

namespace Bravo
{
	class BRAVO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		Scope<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// this function will define in CLIENT
	Bravo::Application* CreateApplication();
}

