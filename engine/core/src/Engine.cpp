#include <engine/core/Engine.hpp>

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

		void mouseMovement(GLFWwindow* glfwWindow, double mouseX, double mouseY)
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

	Engine::Engine(const std::string& title, int width, int height) : m_window(title, width, height), m_inputHandler(&m_window), m_time(glfwGetTime()), m_scene(this)
	{
		m_window.setUserData(this);
		m_window.setResizeCallback(resizeWindow);
		m_window.setCursorMovementCallback(mouseMovement);
		m_window.setScrollCallback(scrollCallback);
		m_inputHandler.setCursorMode(GLFW_CURSOR_DISABLED);
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
			m_scene.updateScene(m_time.getDeltaTime());
			m_window.render();
			processInput(*this);

			m_inputHandler.resetMouseOffset();
			glfwSwapBuffers(m_window.getGLFWWindow());
			glfwPollEvents();
		}
	}

	void Engine::stop()
	{
		m_isRunning = false;
	}

} //gam703::engine::core
