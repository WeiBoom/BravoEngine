#include "../define.h"
#include "OpenGLContext.h"

namespace Bravo
{
	static void on_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->on_key(key, scancode, action, mods);
	}

	static void on_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		auto pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->on_scroll(yoffset);
	}

	static void on_window_size_callback(GLFWwindow* window, int width, int height)
	{
		auto pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window));
		pWindow->on_resize(width, height);
	}

	static void on_window_close_callback(GLFWwindow* window)
	{
		Bravo::IWindow* pWindow = static_cast<Bravo::IWindow*>(glfwGetWindowUserPointer(window););
		pWindow->on_close();
	}

	static void fragment_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


	bool OpenGLContext::init(Bravo::IWindow* window)
	{
		__super::init(window);
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
		window->set_native_window(glWindow);

		if (!glWindow)
		{
			fprintf(stderr, "Error: GLFW Window couldn't be created\n");
			return false;
		}

		// set window callback
		glfwSetWindowUserPointer(glWindow, window);
		glfwSetFramebufferSizeCallback(glWindow, fragment_size_callback);
		glfwSetScrollCallback(glWindow, on_scroll_callback);
		glfwSetWindowSizeCallback(glWindow, on_window_size_callback);
		glfwSetWindowCloseCallback(glWindow, on_window_close_callback);
		// make current context
		glfwMakeContextCurrent(glWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			fprintf(stderr, "Error: initialize GLAD failed\n");
			return false;
		}

		glEnable(GL_DEPTH_TEST);

		return true;
	}

	void OpenGLContext::pre_render()
	{
		glViewport(0, 0, m_window->Width, m_window->Height);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLContext::post_render()
	{
		glfwPollEvents();
		glfwSwapBuffers((GLFWwindow*)m_window->get_native_window());
	}

	void OpenGLContext::end()
	{
		glfwDestroyWindow((GLFWwindow*)m_window->get_native_window());
		glfwTerminate();
	}
}
