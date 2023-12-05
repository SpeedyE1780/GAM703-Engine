#include <glad/glad.h>
#include <core/Engine.hpp>
#include <graphic/Model.hpp>
#include <graphic/Shader.hpp>

namespace gam703::engine::core
{
	namespace
	{
		void resizeWindow(GLFWwindow* glfwWindow, int width, int height)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getWindow().resizeWindow(width, height);
			}
		}

		void processInput(Engine& engine)
		{
			Input& inputHandler = engine.getInput();

			if (inputHandler.isKeyPressed(GLFW_KEY_ESCAPE))
			{
				engine.stop();
			}

			if (auto* camera = engine.getMainCamera())
			{
				float deltaTime = engine.getDeltaTime();

				if (inputHandler.isKeyPressed(GLFW_KEY_W))
				{
					camera->ProcessKeyboard(gam703::engine::components::FORWARD, deltaTime);
				}

				if (inputHandler.isKeyPressed(GLFW_KEY_S))
				{
					camera->ProcessKeyboard(gam703::engine::components::BACKWARD, deltaTime);
				}

				if (inputHandler.isKeyPressed(GLFW_KEY_A))
				{
					camera->ProcessKeyboard(gam703::engine::components::LEFT, deltaTime);
				}

				if (inputHandler.isKeyPressed(GLFW_KEY_D))
				{
					camera->ProcessKeyboard(gam703::engine::components::RIGHT, deltaTime);
				}

				camera->ProcessMouseMovement(inputHandler.getMouseOffsetX(), inputHandler.getMouseOffsetY());
				camera->ProcessMouseScroll(inputHandler.getMouseScrollOffsetY());
			}
		}

		void mouseMovment(GLFWwindow* glfwWindow, double mouseX, double mouseY)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getInput().processMouseMovement(mouseX, mouseY);
			}
		}

		void scrollCallback(GLFWwindow* glfwWindow, double xOffset, double yOffset)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getInput().processMouseScroll(xOffset, yOffset);
			}
		}
	}

	Engine::Engine(const std::string& title, int width, int height) : m_window(title, width, height), m_inputHandler(m_window.getGLFWWindow())
	{
		if (auto* glfwWindow = m_window.getGLFWWindow())
		{
			glfwSetWindowUserPointer(glfwWindow, this);
			glfwSetFramebufferSizeCallback(glfwWindow, resizeWindow);
			glfwSetCursorPosCallback(glfwWindow, mouseMovment);
			glfwSetScrollCallback(glfwWindow, scrollCallback);
			glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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

			m_inputHandler.resetMouseOffset();
			glfwSwapBuffers(m_window.getGLFWWindow());
			glfwPollEvents();
		}
	}

	void Engine::stop()
	{
		m_isRunning = false;
		glfwSetWindowShouldClose(m_window.getGLFWWindow(), true);
	}

} //gam703::engine::core
