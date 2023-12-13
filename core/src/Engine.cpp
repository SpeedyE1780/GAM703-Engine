#include <core/Engine.hpp>

namespace gam703::engine::core
{
	namespace
	{
		void resizeWindow(GLFWwindow* glfwWindow, int width, int height)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getWindow().resizeWindow(width, height);
				engine->getScene()->getSceneRenderer()->calculateProjectionMatrix(engine->getWindow().getAspectRatio());
			}
		}

		void processInput(Engine& engine)
		{
			auto* inputHandler = engine.getInput();

			if (inputHandler->isKeyPressed(GLFW_KEY_ESCAPE))
			{
				engine.stop();
			}
		}

		void mouseMovment(GLFWwindow* glfwWindow, double mouseX, double mouseY)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getInput()->processMouseMovement(mouseX, mouseY);
			}
		}

		void scrollCallback(GLFWwindow* glfwWindow, double xOffset, double yOffset)
		{
			if (auto* engine = static_cast<Engine*>(glfwGetWindowUserPointer(glfwWindow)))
			{
				engine->getInput()->processMouseScroll(xOffset, yOffset);
			}
		}
	}

	Engine::Engine(const std::string& title, int width, int height) : m_window(title, width, height), m_inputHandler(m_window.getGLFWWindow()), m_time(glfwGetTime()), m_scene(this)
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
		while (m_isRunning)
		{
			m_time.processTime(glfwGetTime());
			processInput(*this);
			m_scene.updateScene(m_time.getDeltaTime());

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
