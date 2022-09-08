#include "GLWindow.h"
namespace Bravo
{
	GLWindow::~GLWindow()
	{
	}

	bool GLWindow::Init(int width, int height, const std::string& title)
	{
		Width = width;
		Height = height;
		Title = title;

		// todo
		// 1. 初始化渲染窗口
		m_RenderContext->Init(this);
		// 2. 初始化ImGui
		m_UIContext->Init(this);

		return m_IsRunning;
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
		std::shared_ptr<Shader> shader2 = std::make_shared<Shader>("Artwork\\Shaders\\blue.shader");
		std::shared_ptr<Material> mat1 = std::make_shared<Material>(shader);
		std::shared_ptr<Material> mat2 = std::make_shared<Material>(shader2);

		m_RenderContext->PushRenderer(new Renderer(mesh1, mat1));
		m_RenderContext->PushRenderer(new Renderer(mesh2, mat2));
		m_RenderContext->PushRenderer(new Renderer(mesh3, mat2));
	}

	void GLWindow::Render()
	{
		m_RenderContext->PreRender();
		m_UIContext->PreRender();

		m_RenderContext->Render();

		m_UIContext->PostRender();
		m_RenderContext->PostRender();
	}

	void GLWindow::HandleInput()
	{
	}

	void GLWindow::OnScroll(double delta)
	{
	}

	void GLWindow::OnKey(int key, int scancode, int action, int mods)
	{
	}

	void GLWindow::OnResize(int width, int height)
	{
	}

	void GLWindow::OnClose()
	{
		m_IsRunning = false;

		m_RenderContext->End();
		m_UIContext->End();
	}


}



