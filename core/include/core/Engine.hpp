#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <gui/Window.hpp>
#include <components/Camera.hpp>

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

		void start();
		void stop();

		components::Camera* getMainCamera() { return m_mainCamera; }
		const components::Camera* getMainCamera() const { return m_mainCamera; }

		float getDeltaTime() const { return m_deltaTime; }

		void processMouseMovement(GLFWwindow* glfwWindow, double mouseX, double mouseY);

	private:
		void run();

		gui::Window m_window;
		components::Camera* m_mainCamera = nullptr;
		bool m_isRunning = false;
		float m_deltaTime = 0;
		float m_lastFrame = 0;
		double m_lastMouseX = 0;
		double m_lastMouseY = 0;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
