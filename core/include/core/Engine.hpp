#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <components/Camera.hpp>
#include <core/Input.hpp>
#include <gui/Window.hpp>

#include <string>

namespace gam703::engine::core
{
	class Engine
	{
	public:
		Engine(const std::string& title, int width, int height);
		~Engine();

		gui::Window& getWindow() { return m_window; }
		const gui::Window& getWindow() const { return m_window; }

		Input& getInput() { return m_inputHandler; }
		const Input& getInput() const { return m_inputHandler; }

		void start();
		void stop();

		components::Camera* getMainCamera() { return m_mainCamera; }
		const components::Camera* getMainCamera() const { return m_mainCamera; }

		float getDeltaTime() const { return m_deltaTime; }

		void processMouseMovement(GLFWwindow* glfwWindow, double mouseX, double mouseY);

	private:
		void run();

		gui::Window m_window;
		Input m_inputHandler;
		components::Camera* m_mainCamera = nullptr;
		bool m_isRunning = false;
		float m_deltaTime = 0;
		float m_lastFrame = 0;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
