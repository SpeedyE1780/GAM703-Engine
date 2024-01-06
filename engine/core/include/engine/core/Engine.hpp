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
	/// @brief Engine runs the entire game
	class ENGINE_CORE_API Engine
	{
	public:
		/// @brief Create an engine to run the game
		/// @param title The game name
		/// @param width The Window width
		/// @param height The window height
		Engine(const std::string& title, int width, int height);

		/// @brief Cleans up all allocated resources
		~Engine();

		/// @brief Get the game window
		/// @return The game window
		gui::Window& getWindow() { return m_window; }

		/// @brief Get the game window
		/// @return The game window
		const gui::Window& getWindow() const { return m_window; }

		/// @brief Get the game input handler
		/// @return The game input handler
		Input& getInput() { return m_inputHandler; }

		/// @brief Get the game input handler
		/// @return The game input handler
		const Input& getInput() const { return m_inputHandler; }

		/// @brief Get the time processor
		/// @return The time processor
		Time& getTime() { return m_time; }

		/// @brief Get the time processor
		/// @return The time processor
		const Time& getTime() const { return m_time; }

		/// @brief Get the scene containing all scene objects
		/// @return The scene containing all scene objects
		Scene& getScene() { return m_scene; }

		/// @brief Get the scene containing all scene objects
		/// @return The scene containing all scene objects
		const Scene& getScene() const { return m_scene; }

		/// @brief Get the resource manager containing all loaded models and textures
		/// @return The resource manager containing all loaded models and textures
		ResourceManager& getResourceManager() { return m_resourceManager; }

		/// @brief Get the resource manager containing all loaded models and textures
		/// @return The resource manager containing all loaded models and textures
		const ResourceManager& getResourceManager() const { return m_resourceManager; }

		/// @brief Get the audio engine controlling the game audio
		/// @return The audio engine controlling the game audio
		audio::AudioEngine& getAudioEngine() { return m_audioEngine; }

		/// @brief Get the audio engine controlling the game audio
		/// @return The audio engine controlling the game audio
		const audio::AudioEngine& getAudioEngine() const { return m_audioEngine; }

		/// @brief Start the game engine
		void start();

		/// @brief Stop the game engine
		void stop();

	private:
		/// @brief Start the update loop
		void run();

		/// @brief Render the games GUI
		void renderGUI();

		/// @brief The window where the 3D models and gui are rendered
		gui::Window m_window;
		/// @brief The game input handler
		Input m_inputHandler;
		/// @brief The time processor
		Time m_time;
		/// @brief The scene containing all scene objects
		Scene m_scene;
		/// @brief The resource manager containing all loaded models and textures
		ResourceManager m_resourceManager{};
		/// @brief The audio engine controlling the game audio
		audio::AudioEngine m_audioEngine{};
		/// @brief Stores if the engine is running
		bool m_isRunning = false;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
