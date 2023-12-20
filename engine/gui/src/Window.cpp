#include <engine/gui/Window.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace gam703::engine::gui
{
	namespace
	{
		void initializeGLFW()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		}

		void initialzeGlad()
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
			}
		}
	}

	Window::Window(const std::string& title, int width, int height) :m_window(nullptr), m_title(title), m_width(width), m_height(height)
	{
		initializeGLFW();

		if (m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr))
		{
			glfwMakeContextCurrent(m_window);
			initialzeGlad();
		}
		else
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}

		glEnable(GL_DEPTH_TEST);
	}

	std::pair<double, double> Window::getMousePosition() const
	{
		double x = 0, y = 0;
		glfwGetCursorPos(m_window, &x, &y);
		return { x, y };
	}

	bool Window::isKeyPressed(int key) const
	{
		return glfwGetKey(m_window, key) == GLFW_PRESS;
	}

	void Window::resizeWindow(int width, int height)
	{
		m_width = width;
		m_height = height;
		glViewport(0, 0, width, height);
	}

	void Window::setUserData(void* userData)
	{
		glfwSetWindowUserPointer(m_window, userData);
	}

	void Window::setResizeCallback(GLFWframebuffersizefun callback)
	{
		glfwSetFramebufferSizeCallback(m_window, callback);
	}

	void Window::setCursorMovementCallback(GLFWcursorposfun callback)
	{
		glfwSetCursorPosCallback(m_window, callback);
	}

	void Window::setScrollCallback(GLFWscrollfun callback)
	{
		glfwSetScrollCallback(m_window, callback);
	}

	void Window::setCursorMode(int mode)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, mode);
	}

} //gam703::engine::gui
