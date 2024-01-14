#include <engine/audio/AudioMixer.hpp>

#include <engine/utility/Math.hpp>

#include <algorithm>

namespace gam703::engine::audio
{
	void AudioMixer::addAudioSource(AudioSource* source)
	{
		if (source)
		{
			m_sources.push_back(source);
		}
	}

	void AudioMixer::removeAudioSource(AudioSource* source)
	{
		auto newEnd = std::remove(begin(m_sources), end(m_sources), source);
		m_sources.erase(newEnd, end(m_sources));
	}

	void AudioMixer::setVolume(float volume)
	{
		if (m_volume != volume)
		{
			m_volume = utility::clamp(volume, 0.0f, 1.0f);;
			updateAudioSources();
		}
	}

	void AudioMixer::setParentMixer(AudioMixer* mixer)
	{
		if (m_parent != mixer)
		{
			if (m_parent)
			{
				auto newEnd = std::remove(begin(m_parent->m_children), end(m_parent->m_children), this);
				m_parent->m_children.erase(newEnd, end(m_parent->m_children));
			}

			if (m_parent = mixer)
			{
				m_parent->m_children.push_back(this);
			}

			updateAudioSources();
		}
	}

	void AudioMixer::updateAudioSources() const
	{
		std::for_each(begin(m_sources), end(m_sources), [](AudioSource* source) { source->updateVolume(); });
		std::for_each(begin(m_children), end(m_children), [](AudioMixer* mixer) { mixer->updateAudioSources(); });
	}
}
