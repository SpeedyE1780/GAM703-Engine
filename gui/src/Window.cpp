#include <glad/glad.h>
#include <gui/Window.hpp>
#include <graphic/Shader.hpp>
#include <graphic/Model.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace gam703::engine::gui
{
	namespace
	{
		void initializeGLFW()
		{
			// glfw: initialize and configure
			// ------------------------------
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		}
		// glfw: whenever the window size changed (by OS or user resize) this callback function executes
		// ---------------------------------------------------------------------------------------------
		void ResizeWindow(GLFWwindow* window, int width, int height)
		{
			// make sure the viewport matches the new window dimensions; note that width and
			// height will be significantly larger than specified on retina displays.
			glViewport(0, 0, width, height);
		}

		void initialzeGlad()
		{
			// glad: load all OpenGL function pointers
			// ---------------------------------------
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
			}
		}

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
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
			glfwSetFramebufferSizeCallback(m_window, ResizeWindow);
			initialzeGlad();
		}
		else
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}

		// configure global opengl state
		// -----------------------------
		glEnable(GL_DEPTH_TEST);
		// tell GLFW to capture our mouse
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::render()
	{
		graphic::Model ourModel("resources/Models/backpack/backpack.obj");

		graphic::Shader shader = graphic::createDefaultShader();

		while (!glfwWindowShouldClose(m_window))
		{
			// input
			// -----
			processInput(m_window);

			// render
			// ------
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			shader.use();

			// view/projection transformations
			glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)m_width / (float)m_height, 0.1f, 100.0f);
			glm::mat4 view = glm::lookAt(glm::vec3(0.0f,0.0f,3.0f), glm::vec3(), glm::vec3(0,1.0f,0.f));
			shader.setMat4("projection", projection);
			shader.setMat4("view", view);

			// render the loaded model
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
			model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
			shader.setMat4("model", model);

			ourModel.draw(shader);

			// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
			// -------------------------------------------------------------------------------
			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}
} //gam703::engine::gui
