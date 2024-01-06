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

	AudioMixer* AudioEngine::addAudioMixer(const std::string& name)
	{
		m_audioMixers.emplace(name, AudioMixer());
		return &m_audioMixers.at(name);
	}

	AudioMixer* AudioEngine::getAudioMixer(const std::string& name)
	{
		if (auto audioMixer = m_audioMixers.find(name); audioMixer != m_audioMixers.end())
		{
			return &audioMixer->second;
		}

		return nullptr;
	}
}
