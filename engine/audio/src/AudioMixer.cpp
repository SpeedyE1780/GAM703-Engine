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
		m_volume = utility::clamp(volume, 0.0f, 1.0f);;

		std::for_each(begin(m_sources), end(m_sources), [](AudioSource* source) { source->updateVolume(); });
	}
}
