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
		GLWindow() : m_isRunning(true),m_window(nullptr) {
			m_UIContext = std::make_unique<UIContext>();
			m_RenderContext = std::make_unique<OpenGLContext>();
		}
		~GLWindow();
	public:
		bool init(int width, int height, const std::string& title);

		bool is_running() { return m_isRunning; }

		void render();

		void handle_input();

	// implement interface
	public :

		void on_scroll(double delta) override;

		void on_key(int key, int scancode, int action, int mods) override;

		void on_resize(int width, int height) override;

		void on_close() override;

		void* get_native_window() override { return m_window; }

		void set_native_window(void* window) override { m_window = (GLFWwindow*)window; }
		
	private :

		bool m_isRunning;
		GLFWwindow* m_window;

		// ui 
		std::unique_ptr<UIContext> m_UIContext;
		// render
		std::unique_ptr<OpenGLContext> m_RenderContext;


	};
}

