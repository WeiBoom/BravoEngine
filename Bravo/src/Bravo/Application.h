#pragma once

#include "Bravo/Core/Base.h"

#include "Bravo/Core/Window.h"

namespace Bravo
{
	class BRAVO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		Scope<Window> m_Window;
		bool m_Running = true;
	};

	// this function will define in CLIENT
	Bravo::Application* CreateApplication();
}

