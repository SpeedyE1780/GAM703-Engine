#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <engine/audio/AudioEngine.hpp>

#include <engine/core/Config.hpp>
#include <engine/core/Input.hpp>
#include <engine/core/ResourceManager.hpp>
#include <engine/core/Scene.hpp>
#include <engine/core/Time.hpp>

#include <engine/gui/Window.hpp>

#include <string>

namespace gam703::engine::core
{
	class ENGINE_CORE_API Engine
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
		Scene& getScene() { return m_scene; }
		const Scene& getScene() const { return m_scene; }
		ResourceManager& getResourceManager() { return m_resourceManager; }
		const ResourceManager& getResourceManager() const { return m_resourceManager; }
		audio::AudioEngine& getAudioEngine() { return m_audioEngine; }
		const audio::AudioEngine& getAudioEngine() const { return m_audioEngine; }

		void start();
		void stop();

	private:
		void run();
		void renderGUI();

		gui::Window m_window;
		Input m_inputHandler;
		Time m_time;
		Scene m_scene;
		ResourceManager m_resourceManager{};
		audio::AudioEngine m_audioEngine{};
		bool m_isRunning = false;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
