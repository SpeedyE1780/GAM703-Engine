#include <engine/audio/AudioEngine.hpp>
#include <engine/audio/AudioMixer.hpp>
#include <engine/audio/AudioSource.hpp>

#include <engine/utility/Math.hpp>

#include <iostream>

namespace gam703::engine::audio
{
	AudioSource::AudioSource(AudioEngine& engine, irrklang::ISoundSource& source) : m_engine(engine), m_soundSource(source)
	{
	}

	AudioSource::~AudioSource()
	{
		try
		{
			if (m_activeSound)
			{
				if (auto* activeSoundSource = m_activeSound->getSoundSource())
				{
					std::cout << "DROPPING SOUND SOURCE: " << activeSoundSource->getName() << std::endl;
				}

				m_activeSound->drop();
			}
		}
		catch(...)
		{
			std::cout << "WEIRD SOUND DROP ERROR" << std::endl;
		}
	}

	void AudioSource::setVolume(float volume)
	{
		if (m_volume != volume)
		{
			m_volume = utility::clamp(volume, 0.0f, 1.0f);
			updateVolume();
		}
	}

	float AudioSource::getOutputVolume() const
	{
		return m_audioMixer ? m_audioMixer->getOutputVolume() * m_volume : m_volume;
	}

	void AudioSource::updateVolume() const
	{
		float volume = getOutputVolume();

		m_soundSource.setDefaultVolume(volume);

		if (m_activeSound)
		{
			m_activeSound->setVolume(volume);
		}
	}

	void AudioSource::play(bool loop) const
	{
		updateVolume();

		if (m_activeSound)
		{
			m_activeSound->drop();
		}

		m_activeSound = m_engine.play(*this, loop);
		m_activeSound->setSoundStopEventReceiver(const_cast<AudioSource*>(this), nullptr);
	}

	void AudioSource::setAudioMixer(AudioMixer* mixer)
	{
		if (m_audioMixer != mixer)
		{
			if (m_audioMixer)
			{
				m_audioMixer->removeAudioSource(this);
			}

			if (m_audioMixer = mixer)
			{
				m_audioMixer->addAudioSource(this);
			}

			updateVolume();
		}
	}

	void AudioSource::OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData)
	{
		if (m_activeSound)
		{
			m_activeSound->drop();
			m_activeSound = nullptr;
		}
	}
}
