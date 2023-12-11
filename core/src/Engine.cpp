#include <glad/glad.h>
#include <core/Engine.hpp>
#include <core/SceneRenderer.hpp>
#include <components/Transform.hpp>
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
				engine->getSceneRenderer()->calculateProjectionMatrix();
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

	Engine::Engine(const std::string& title, int width, int height) : m_window(title, width, height), m_inputHandler(m_window.getGLFWWindow()), m_time(glfwGetTime()), m_sceneRenderer(&m_window)
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
		const core_interface::IModel* ourModel = m_resourceManager.getModel("resources/Models/backpack/backpack.obj");
		const core_interface::IModel* ourModel2 = m_resourceManager.getModel("resources/Models/backpack/backpack.obj");
		const core_interface::IModel* ourModel3 = m_resourceManager.getModel("resources/Models/backpack/backpack.obj");
		const core_interface::IModel* ourModel4 = m_resourceManager.getModel("resources/Models/backpack/backpack.obj");

		components::Transform cameraTransform(this, glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0, glm::radians(-90.0f), 0));
		m_mainCamera = cameraTransform.addComponent<components::Camera>();

		components::Transform backpackTransform{ this, glm::vec3(0.0f, 0.0f, 0.0f) };
		backpackTransform.addComponent<components::Renderer>(ourModel);

		components::Transform backpackTransform2{ this, glm::vec3(1.0f, 1.0f, 0.0f) };
		backpackTransform2.addComponent<components::Renderer>(ourModel2);

		components::Transform backpackTransform3{ this, glm::vec3(2.0f, 2.0f, 0.0f) };
		backpackTransform3.addComponent<components::Renderer>(ourModel3);

		components::Transform backpackTransform4{ this, glm::vec3(3.0f, 3.0f, 0.0f) };
		backpackTransform4.addComponent<components::Renderer>(ourModel4);

		m_sceneRenderer.setMainCamera(m_mainCamera);

		while (m_isRunning)
		{
			m_time.processTime(glfwGetTime());
			processInput(*this);
			m_mainCamera->tick(m_time.getDeltaTime());
			cameraTransform.calculateTransformMatrix();
			m_sceneRenderer.render();

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
