#include "pch.h"
#include "WinWindow.h"

namespace Bravo
{
	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		BRAVO_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	WinWindow::WinWindow(const WindowProps& props)
	{
		Init(props);
	}

	WinWindow::~WinWindow()
	{
		Shutdown();
	}


	void WinWindow::Init(const WindowProps& props)
	{

	}
	void WinWindow::Shutdown()
	{
	}

	void WinWindow::OnUpdate()
	{
	}

	void WinWindow::SetVSync(bool enabled)
	{
	}

	bool WinWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}