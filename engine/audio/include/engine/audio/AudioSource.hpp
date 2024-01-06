#ifndef GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP

#include <engine/audio/Config.hpp>
#include <engine/audio/AudioEngine.fwd.hpp>

#include <irrklang/irrKlang.h>

namespace gam703::engine::audio
{
	class ENGINE_AUDIO_API AudioSource
	{
	public:
		AudioSource(AudioEngine& engine, irrklang::ISoundSource& source);

		irrklang::ISoundSource* getSoundSource() const { return &m_soundSource; }

		void play() const;

	private:
		AudioEngine& m_engine;
		irrklang::ISoundSource& m_soundSource;
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_SOURCE_HPP
