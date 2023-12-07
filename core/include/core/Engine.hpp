#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <components/Camera.hpp>
#include <core/Config.hpp>
#include <core/Input.hpp>
#include <core/Time.hpp>
#include <gui/Window.hpp>

#include <string>

namespace gam703::engine::core
{
	class CORE_API Engine
	{
	public:
		Engine(const std::string& title, int width, int height);
		~Engine();

		gui::Window& getWindow() { return m_window; }
		const gui::Window& getWindow() const { return m_window; }
		Input& getInput() { return m_inputHandler; }
		const Input& getInput() const { return m_inputHandler; }
		Time& getTime() { return m_time; }
		const Time& getTime() const { return m_time; }
		components::Camera* getMainCamera() { return m_mainCamera; }
		const components::Camera* getMainCamera() const { return m_mainCamera; }

		void start();
		void stop();

	private:
		void run();

		gui::Window m_window;
		Input m_inputHandler;
		Time m_time;
		components::Camera* m_mainCamera = nullptr;
		bool m_isRunning = false;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
