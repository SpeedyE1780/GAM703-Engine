#include <engine/audio/AudioEngine.hpp>

#include <iostream>

namespace gam703::engine::audio
{
	AudioEngine::AudioEngine() : m_engine(irrklang::createIrrKlangDevice())
	{
	}

	AudioEngine::~AudioEngine()
	{
		m_engine->drop();
	}

	AudioSource* AudioEngine::getAudioSource(const std::string& audioFile)
	{
		if (auto audioSource = m_audioSources.find(audioFile); audioSource != m_audioSources.end())
		{
			return &audioSource->second;
		}

		if (auto* soundSource = m_engine->addSoundSourceFromFile(audioFile.c_str()))
		{
			m_audioSources.emplace(audioFile, AudioSource(*this, *soundSource));
			std::cout << "SOUND SOURCE LOADED COUNT: " << m_audioSources.size() << std::endl;
			return &m_audioSources.at(audioFile);
		}

		std::cout << "ERROR SOUND SOURCE NOT FOUND" << std::endl;
		return nullptr;
	}
}
