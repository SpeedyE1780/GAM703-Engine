#include <glad/glad.h>
#include <core/Engine.hpp>
#include <graphic/Model.hpp>
#include <graphic/Shader.hpp>

namespace gam703::engine::core
{
	namespace
	{
		void ResizeWindow(GLFWwindow* glfwWindow, int width, int height)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getWindow().resizeWindow(width, height);
			}
		}

		void processInput(Engine& engine)
		{
			if (auto* window = engine.getWindow().getGLFWWindow())
			{
				if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				{
					engine.stop();
					glfwSetWindowShouldClose(window, true);
				}

				if (auto* camera = engine.getMainCamera())
				{
					float deltaTime = engine.getDeltaTime();

					if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
						camera->ProcessKeyboard(gam703::engine::components::FORWARD, deltaTime);
					if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
						camera->ProcessKeyboard(gam703::engine::components::BACKWARD, deltaTime);
					if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
						camera->ProcessKeyboard(gam703::engine::components::LEFT, deltaTime);
					if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
						camera->ProcessKeyboard(gam703::engine::components::RIGHT, deltaTime);
				}
			}
		}

		//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
		//{
		//	float xpos = static_cast<float>(xposIn);
		//	float ypos = static_cast<float>(yposIn);
		//	static bool firstMouse = true;
		//	static float lastX;
		//	static float lastY;

		//	if (firstMouse)
		//	{
		//		lastX = xpos;
		//		lastY = ypos;
		//		firstMouse = false;
		//	}

		//	float xoffset = xpos - lastX;
		//	float yoffset = lastY - ypos;

		//	lastX = xpos;
		//	lastY = ypos;

		//	camera->ProcessMouseMovement(xoffset, yoffset);
		//}

		//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		//{
		//	camera->ProcessMouseScroll(static_cast<float>(yoffset));
		//}
	}

	Engine::Engine(const std::string& title, int width, int height) : m_window(title, width, height)
	{
		if (auto* glfwWindow = m_window.getGLFWWindow())
		{
			glfwSetWindowUserPointer(glfwWindow, this);
			glfwSetFramebufferSizeCallback(glfwWindow, ResizeWindow);
			//glfwSetCursorPosCallback(glfwWindow, mouse_callback);
			//glfwSetScrollCallback(glfwWindow, scroll_callback);
			glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}

	Engine::~Engine()
	{
		glfwTerminate();
	}

	void Engine::start()
	{
		m_isRunning = true;
		run();
	}

	void Engine::run()
	{
		graphic::Model ourModel("resources/Models/backpack/backpack.obj");
		graphic::Shader shader = graphic::createDefaultShader();

		components::Camera sceneCamera(glm::vec3(0.0f, 0.0f, 10.0f));
		m_mainCamera = &sceneCamera;

		while (m_isRunning)
		{
			float currentFrame = static_cast<float>(glfwGetTime());
			m_deltaTime = currentFrame - m_lastFrame;
			m_lastFrame = currentFrame;

			processInput(*this);
			m_window.render(sceneCamera, shader, ourModel);

			glfwSwapBuffers(m_window.getGLFWWindow());
			glfwPollEvents();
		}
	}

	void Engine::stop()
	{
		m_isRunning = false;
	}

} //gam703::engine::core
