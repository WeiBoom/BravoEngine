#pragma once

#include "Bravo/Core/Base.h"

namespace Bravo
{
	class BRAVO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// this function will define in CLIENT
	Bravo::Application* CreateApplication();
}

