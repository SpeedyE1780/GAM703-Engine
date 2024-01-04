#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <engine/core/Config.hpp>
#include <engine/core/Input.hpp>
#include <engine/core/ResourceManager.hpp>

#include <engine/core-interfaces/IEngine.hpp>

#include <engine/gui/Window.hpp>

#include <string>

namespace gam703::engine::core
{
	class ENGINE_CORE_API Engine : public core_interface::IEngine
	{
	public:
		Engine(const std::string& title, int width, int height);
		~Engine();

		gui::Window& getWindow() { return m_window; }
		const gui::Window& getWindow() const { return m_window; }
		virtual core_interface::IInput* getInput() override { return &m_inputHandler; }
		virtual const core_interface::IInput* getInput() const override { return &m_inputHandler; }
		core_interface::Time* getTime() { return &m_time; }
		const core_interface::Time* getTime() const { return &m_time; }
		virtual core_interface::IResourceManager* getResourceManager() override { return &m_resourceManager; }
		virtual const core_interface::IResourceManager* getResourceManager() const override { return &m_resourceManager; }

		virtual float getAspectRatio() const override { return m_window.getAspectRatio(); }

		void start();
		void stop();

	private:
		void run();
		void renderGUI();

		gui::Window m_window;
		Input m_inputHandler;
		ResourceManager m_resourceManager{};
		bool m_isRunning = false;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
