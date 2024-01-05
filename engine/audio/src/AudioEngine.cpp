#include <engine/audio/AudioEngine.hpp>

namespace gam703::engine::audio
{
	AudioEngine::AudioEngine() : m_engine(irrklang::createIrrKlangDevice())
	{
	}

	AudioEngine::~AudioEngine()
	{
		m_engine->drop();
	}

	void AudioEngine::play(const std::string& audioFile) const
	{
		m_engine->play2D(audioFile.c_str());
	}
}
