#pragma once

#include "define.h"
#include "window/GLWindow.h"

namespace Bravo
{
	class Application
	{
	public:
		Application(const std::string& app_name);
		void Loop();
	public:
		static Application& Get() { return *s_instance; }
	private:
		static Application* s_instance;

		std::unique_ptr<GLWindow> m_window;
	};
}

