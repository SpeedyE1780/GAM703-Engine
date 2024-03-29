#include <engine/gui/Window.hpp>
#include <engine/gui/Text.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>
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

	Window::Window(const std::string& title, int width, int height) : m_window(nullptr), m_title(title), m_width(width), m_height(height)
	{
		initializeGLFW();
		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

		if (!m_window)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_window);
		initialzeGlad();

		glEnable(GL_DEPTH_TEST);
	}

	Window::~Window()
	{
		glfwSetWindowShouldClose(m_window, true);
	}

	std::pair<double, double> Window::getMousePosition() const
	{
		double x = 0, y = 0;
		glfwGetCursorPos(m_window, &x, &y);
		return { x, y };
	}

	void Window::resizeWindow(int width, int height)
	{
		m_width = width;
		m_height = height;
		glViewport(0, 0, width, height);
	}

	void Window::render(ImGuiContext* context) const
	{
		ImGui::SetCurrentContext(context);

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
		ImGuiIO& io = ImGui::GetIO();
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		std::for_each(begin(m_elements), end(m_elements), [](const std::unique_ptr<GUIElement>& element) { element->render(); });
		ImGui::End();
	}

} //gam703::engine::gui
