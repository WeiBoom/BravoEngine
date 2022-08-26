#pragma once

#include "../define.h"
#include "../render/UIContext.h"
#include "../render/OpenGLContext.h"

#include "IWindow.h"

namespace Bravo
{
	class GLWindow : public IWindow
	{
	public:
		GLWindow() : m_IsRunning(true),m_Window(nullptr) {
			m_UIContext = std::make_unique<UIContext>();
			m_RenderContext = std::make_unique<OpenGLContext>();
		}
		~GLWindow();
	public:
		bool Init(int width, int height, const std::string& title);

		bool IsRunning() { return m_IsRunning; }

		void PrepareData();

		void Render();

		void HandleInput();

	// implement interface
	public :

		void OnScroll(double delta) override;

		void OnKey(int key, int scancode, int action, int mods) override;

		void OnResize(int width, int height) override;

		void OnClose() override;

		void* GetNativeWindow() override { return m_Window; }

		void SetNativeWindow(void* window) override { m_Window = (GLFWwindow*)window; }
		
	private :

		bool m_IsRunning;
		GLFWwindow* m_Window;

		// ui 
		std::unique_ptr<UIContext> m_UIContext;
		// render
		std::unique_ptr<OpenGLContext> m_RenderContext;


	};
}

