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

	void GLWindow::PrepareData() 
	{
		const float vertex[] = {
			-0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f,  0.0f, 1.0f,
			0.0f, 1.0f, 0.5f, 1.5f,
		};

		const unsigned int indices1[] = { 0, 1, 3 };
		const unsigned int indices2[] = { 1, 2, 3 };
		const unsigned int indices3[] = { 4, 2, 3 };

		VertexLayout vbLayout;
		vbLayout.AddElement<float>(2);
		vbLayout.AddElement<float>(2);
		std::shared_ptr<Mesh> mesh1 = std::make_shared<Mesh>(vertex, 5, indices1, 3, vbLayout);
		std::shared_ptr<Mesh> mesh2 = std::make_shared<Mesh>(vertex, 5, indices2, 3, vbLayout);
		std::shared_ptr<Mesh> mesh3 = std::make_shared<Mesh>(vertex, 5, indices3, 3, vbLayout);

		std::shared_ptr<Shader> shader = std::make_shared<Shader>("Artwork\\Shaders\\default.shader");
		std::shared_ptr<Shader> shader2 = std::make_shared<Shader>("Artwork\\Shaders\\default.shader");
		shader->SetVec4("setColor", glm::vec4(0.5, 0.5, 0.5, 1));
		shader2->SetVec4("setColor", glm::vec4(0.5, 0, 0, 1));

		m_RenderContext->PushRenderer(new Renderer(mesh1, shader));
		m_RenderContext->PushRenderer(new Renderer(mesh2, shader2));
		m_RenderContext->PushRenderer(new Renderer(mesh3, shader2));
	}


	void GLWindow::render()
	{
		m_RenderContext->pre_render();
		m_UIContext->pre_render();

		m_RenderContext->Render();

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



