#include "../define.h"
#include "OpenGLContext.h"
#include "GLDebug.h"

GLDebug globalGLDebug;

namespace Bravo
{
	static void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->OnKey(key, scancode, action, mods);
	}

	static void OnScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		auto pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->OnScroll(yoffset);
	}

	static void OnWindowSizeCallback(GLFWwindow* window, int width, int height)
	{
		auto pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->OnResize(width, height);
	}

	static void OnWindowCloseCallback(GLFWwindow* window)
	{
		Bravo::IWindow* pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->OnClose();
	}

	static void FragmentSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void GLAPIENTRY ErrorCallback(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam)
	{
		 globalGLDebug.OutputError(source, type, id, severity, message);
	}

	bool OpenGLContext::Init(Bravo::IWindow* window)
	{
		__super::Init(window);
		if (!glfwInit())
		{
			fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if _APPLE
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		auto glWindow = glfwCreateWindow(window->Width, window->Height, window->Title.c_str(), nullptr, nullptr);
		window->SetNativeWindow(glWindow);

		if (!glWindow)
		{
			fprintf(stderr, "Error: GLFW Window couldn't be created\n");
			return false;
		}

		// set window callback
		glfwSetWindowUserPointer(glWindow, window);
		glfwSetFramebufferSizeCallback(glWindow, FragmentSizeCallback);
		glfwSetScrollCallback(glWindow, OnScrollCallback);
		glfwSetWindowSizeCallback(glWindow, OnWindowSizeCallback);
		glfwSetWindowCloseCallback(glWindow, OnWindowCloseCallback);
		// make current context
		glfwMakeContextCurrent(glWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			fprintf(stderr, "Error: initialize GLAD failed\n");
			return false;
		}

		// version check
		int majorVersion;
		glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
		int minorVersion;
		glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
		fprintf( stdout, "majorVersion: %d, minorVersion: %d\n", majorVersion, minorVersion);
		if (minorVersion > 4) 
		{
			glEnable(GL_DEBUG_OUTPUT);
			glDebugMessageCallback(ErrorCallback, 0);
		}		
		return true;
	}

	void OpenGLContext::PreRender()
	{
		glViewport(0, 0, m_window->Width, m_window->Height);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLContext::PostRender()
	{
		glfwPollEvents();
		glfwSwapBuffers((GLFWwindow*)m_window->GetNativeWindow());
	}

	void OpenGLContext::End()
	{
		glfwDestroyWindow((GLFWwindow*)m_window->GetNativeWindow());
		glfwTerminate();
	}
}
