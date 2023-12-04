#include <glad/glad.h>
#include <gui/Window.hpp>
#include <graphic/Shader.hpp>
#include <graphic/Model.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <components/Camera.hpp>

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

		void ResizeWindow(GLFWwindow* glfwWindow, int width, int height)
		{
			if (auto* window = static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				window->resizeWindow(width, height);
			}
		}

		void initialzeGlad()
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
			}
		}

		void processInput(GLFWwindow* window)
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}
	}

	Window::Window(const std::string& title, int width, int height) :m_window(nullptr), m_title(title), m_width(width), m_height(height)
	{
		initializeGLFW();

		if (m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr))
		{
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this);
			glfwSetFramebufferSizeCallback(m_window, ResizeWindow);
			initialzeGlad();
		}
		else
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}

		glEnable(GL_DEPTH_TEST);
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::resizeWindow(int width, int height)
	{
		m_width = width;
		m_height = height;
		glViewport(0, 0, width, height);
	}

	void Window::render()
	{
		graphic::Model ourModel("resources/Models/backpack/backpack.obj");

		graphic::Shader shader = graphic::createDefaultShader();

		components::Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));

		while (!glfwWindowShouldClose(m_window))
		{
			processInput(m_window);

			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			shader.use();

			glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()), (float)m_width / (float)m_height, 0.1f, 100.0f);
			glm::mat4 view = camera.GetViewMatrix();
			shader.setMat4("projection", projection);
			shader.setMat4("view", view);

			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
			shader.setMat4("model", model);

			ourModel.draw(shader);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}

} //gam703::engine::gui
