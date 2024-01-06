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
	class ENGINE_AUDIO_API AudioEngine
	{
	public:
		AudioEngine();
		~AudioEngine();

		void play(const std::string& audioFile, bool loop = false) const { m_engine->play2D(audioFile.c_str(), loop); }
		irrklang::ISound* play(const AudioSource& audioSource, bool loop = false, bool startPause = false, bool enableSFX = false) const { return m_engine->play2D(audioSource.getSoundSource(), loop, startPause, true, enableSFX); }

		AudioSource* getAudioSource(const std::string& audioFile);

		AudioMixer* addAudioMixer(const std::string& name);
		AudioMixer* getAudioMixer(const std::string& name);

	private:
		irrklang::ISoundEngine* m_engine = nullptr;
		std::map<std::string, AudioSource> m_audioSources{};
		std::map<std::string, AudioMixer> m_audioMixers{};
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP
