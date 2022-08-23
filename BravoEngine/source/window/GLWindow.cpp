#include "GLWindow.h"
namespace Bravo
{
	GLWindow::~GLWindow()
	{
	}

	bool GLWindow::init(int width, int height, const std::string& title)
	{
		Width = width;
		Height = height;
		Title = title;

		// todo
		// 1. 初始化渲染窗口
		m_RenderContext->init(this);
		m_UIContext->init(this);
		// 2. 初始化UI界面

		return m_isRunning;
	}

	void GLWindow::render()
	{
		m_RenderContext->pre_render();
		m_UIContext->pre_render();


		m_UIContext->post_render();
		m_RenderContext->post_render();
	}

	void GLWindow::handle_input()
	{
	}

	void GLWindow::on_scroll(double delta)
	{
	}

	void GLWindow::on_key(int key, int scancode, int action, int mods)
	{
	}

	void GLWindow::on_resize(int width, int height)
	{
	}

	void GLWindow::on_close()
	{
		m_isRunning = false;
	}


}



