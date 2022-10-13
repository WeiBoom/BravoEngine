#include "pch.h"
#include "Bravo/Core/Window.h"

#ifdef BRAVO_PLATFORM_WINDOWS
	#include "Platform/Windows/WinWindow.h"
#endif

namespace Bravo
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef BRAVO_PLATFORM_WINDOWS
		return CreateScope<WinWindow>(props);
#else
		BRAVO_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}