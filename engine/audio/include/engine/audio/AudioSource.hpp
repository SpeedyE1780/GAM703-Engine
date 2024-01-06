#ifndef GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP

#include <engine/audio/Config.hpp>
#include <engine/audio/AudioEngine.fwd.hpp>
#include <engine/audio/AudioMixer.fwd.hpp>

#include <irrklang/irrKlang.h>

namespace gam703::engine::audio
{
	class ENGINE_AUDIO_API AudioSource
	{
	public:
		AudioSource(AudioEngine& engine, irrklang::ISoundSource& source);
		~AudioSource();

		irrklang::ISoundSource* getSoundSource() const { return &m_soundSource; }

		void play(bool loop = false) const;

		void updateVolume() const;
		void setVolume(float volume);
		float getVolume() const { return m_volume; }

		void setAudioMixer(AudioMixer* mixer);

	private:
		AudioEngine& m_engine;
		irrklang::ISoundSource& m_soundSource;
		AudioMixer* m_audioMixer = nullptr;
		mutable irrklang::ISound* m_activeSound = nullptr;
		float m_volume = 1.0f;
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP
