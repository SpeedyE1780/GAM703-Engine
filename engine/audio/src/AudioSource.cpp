#include <engine/audio/AudioEngine.hpp>
#include <engine/audio/AudioSource.hpp>

namespace gam703::engine::audio
{
	AudioSource::AudioSource(AudioEngine& engine, irrklang::ISoundSource& source) : m_engine(engine), m_soundSource(source)
	{
	}

	void AudioSource::play(bool loop) const
	{
		m_engine.play(*this, loop);
	}
}