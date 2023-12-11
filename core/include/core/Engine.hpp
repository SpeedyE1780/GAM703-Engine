#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <components/Camera.hpp>
#include <core/Config.hpp>
#include <core/Input.hpp>
#include <core/SceneRenderer.hpp>
#include <core/Time.hpp>
#include <core-interfaces/IEngine.hpp>
#include <gui/Window.hpp>

#include <string>

namespace gam703::engine::core
{
	class CORE_API Engine : public core_interface::IEngine
	{
	public:
		Engine(const std::string& title, int width, int height);
		~Engine();

		gui::Window& getWindow() { return m_window; }
		const gui::Window& getWindow() const { return m_window; }
		virtual core_interface::IInput* getInput() override { return &m_inputHandler; }
		virtual const core_interface::IInput* getInput() const override { return &m_inputHandler; }
		Time& getTime() { return m_time; }
		const Time& getTime() const { return m_time; }
		components::Camera* getMainCamera() { return m_mainCamera; }
		const components::Camera* getMainCamera() const { return m_mainCamera; }
		virtual core_interface::ISceneRenderer* getSceneRenderer() override { return &m_sceneRenderer; }
		virtual const core_interface::ISceneRenderer* getSceneRenderer() const override { return &m_sceneRenderer; }

		void start();
		void stop();

	private:
		void run();

		gui::Window m_window;
		Input m_inputHandler;
		Time m_time;
		SceneRenderer m_sceneRenderer;
		components::Camera* m_mainCamera = nullptr;
		bool m_isRunning = false;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
