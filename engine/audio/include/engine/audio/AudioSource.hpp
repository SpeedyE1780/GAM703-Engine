#ifndef GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP

#include <engine/audio/Config.hpp>
#include <engine/audio/AudioEngine.fwd.hpp>
#include <engine/audio/AudioMixer.fwd.hpp>

#include <irrklang/irrKlang.h>

namespace gam703::engine::audio
{
	/// @brief AudioSource wraps ISoundSource and allows playing/manipulating ISound
	class ENGINE_AUDIO_API AudioSource
	{
	public:
		/// @brief Create an AudioSource wrapping the ISoundSource
		/// @param engine The audio engine used to play ISound
		/// @param source The wrapped ISoundSource
		AudioSource(AudioEngine& engine, irrklang::ISoundSource& source);

		/// @brief Drops the active ISound currently playing
		~AudioSource();

		/// @brief Get the wrapped ISoundSource
		/// @return The wrapped ISoundSource
		irrklang::ISoundSource* getSoundSource() const { return &m_soundSource; }

		/// @brief Plays the ISoundSource audio
		/// @param loop Loop the audio once it's done playing
		void play(bool loop = false) const;

		/// @brief Updates the ISoundSource and activeSound volume to the new output volume
		void updateVolume() const;

		/// @brief Set the audio source volume
		/// @param volume The new volume
		void setVolume(float volume);

		/// @brief Get the audio source volume
		/// @return The audio source volume
		float getVolume() const { return m_volume; }

		/// @brief Get the volume after being influenced by the audio mixer
		/// @return The audio source volume multiplied by the audio mixer output volume if audio mixer != nullptr
		float getOutputVolume() const;

		/// @brief Set the audio mixer that will influence this audio source
		/// @param mixer The audio mixer that will influence this audio source
		void setAudioMixer(AudioMixer* mixer);

	private:
		/// @brief The game's audio engine
		AudioEngine& m_engine;
		/// @brief The wrapped ISoundSource
		irrklang::ISoundSource& m_soundSource;
		/// @brief The audio mixer influencing the audio source
		AudioMixer* m_audioMixer = nullptr;
		/// @brief The ISound being currently played back
		mutable irrklang::ISound* m_activeSound = nullptr;
		/// @brief The audio source volume
		float m_volume = 1.0f;
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP
