#ifndef GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP

#include <engine/audio/Config.hpp>
#include <engine/audio/AudioSource.hpp>
#include <engine/audio/AudioMixer.hpp>

#include <irrKlang/irrKlang.h>

#include <map>
#include <string>

namespace  gam703::engine::audio
{
	/// @brief AudioEngine handles in game audio using irrklang under the hood and contains all the audio sources and audio mixers
	class ENGINE_AUDIO_API AudioEngine
	{
	public:
		/// @brief Creates a default irrklang engine
		AudioEngine();

		/// @brief Drops irrklang engine
		~AudioEngine();

		/// @brief Plays an audio file using its path
		/// @param audioFile Path to the audio file
		/// @param loop Loop the audio once it's done playing
		void play(const std::string& audioFile, bool loop = false) const { m_engine->play2D(audioFile.c_str(), loop); }

		/// @brief Plays an audio source
		/// @param audioSource Audio source to play
		/// @param loop Loop the audio once it's done playing
		/// @param startPause Pause the source before it starts playing
		/// @param enableSFX Enables SFX on current sound
		/// @return The active sound to allow the Audio Source to manipulate it during playback
		irrklang::ISound* play(const AudioSource& audioSource, bool loop = false, bool startPause = false, bool enableSFX = false) const { return m_engine->play2D(audioSource.getSoundSource(), loop, startPause, true, enableSFX); }

		/// @brief Load/Get audiosource to/from engine audiosources
		/// @param audioFile Path to the audio file
		/// @return The AudioSource or nullptr if the file couldn't be found
		AudioSource* getAudioSource(const std::string& audioFile);

		/// @brief Add audio mixer to engine
		/// @param name The name of the audio mixer
		/// @return The newly added or existing audio mixer
		AudioMixer* addAudioMixer(const std::string& name);

		/// @brief Get audio mixer from engine
		/// @param name The name of the audio mixer
		/// @return The AudioMixer or nullptr if it wasn't found
		AudioMixer* getAudioMixer(const std::string& name);

	private:
		/// @brief The irrklang engine
		irrklang::ISoundEngine* m_engine = nullptr;
		/// @brief List of all audio sources
		std::map<std::string, AudioSource> m_audioSources{};
		/// @brief List of all audio mixers
		std::map<std::string, AudioMixer> m_audioMixers{};
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP
