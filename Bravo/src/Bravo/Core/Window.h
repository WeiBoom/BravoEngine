#pragma once

#include "Bravo/Core/Base.h"
#include "Bravo/Events/Event.h"

namespace Bravo
{

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Bravo Engine",
			unsigned int width = 1280,
			unsigned int height = 720
			):Title(title),Width(width),Height(height)
		{}
	};

	class BRAVO_API Window
	{
	public :
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {};
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}



