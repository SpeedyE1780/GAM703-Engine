#include <gui/Window.hpp>
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

	void Window::resizeWindow(int width, int height)
	{
		m_width = width;
		m_height = height;
		glViewport(0, 0, width, height);
	}

	void Window::render(const components::Camera& sceneCamera, const components::Renderer& renderer) const
	{
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glm::mat4 projection = glm::perspective(glm::radians(sceneCamera.getZoom()), (float)m_width / (float)m_height, 0.1f, 100.0f);
			renderer.render(projection, sceneCamera.GetViewMatrix());
	}

} //gam703::engine::gui
