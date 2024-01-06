#ifndef GAM703_ENGINE_AUDIO_AUDIO_MIXER_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_MIXER_HPP

#include <engine/audio/Config.hpp>
#include <engine/audio/AudioSource.hpp>

#include <vector>

namespace gam703::engine::audio
{
	class ENGINE_AUDIO_API AudioMixer
	{
	public:
		void addAudioSource(AudioSource* source);
		void removeAudioSource(AudioSource* source);

		void setVolume(float volume);
		float getVolume() const { return m_volume; }
		float getOutputVolume() const { return m_parent ? m_parent->getOutputVolume() * m_volume : m_volume; }

		void setParentMixer(AudioMixer* mixer);

	private:
		void updateAudioSources() const;

		AudioMixer* m_parent = nullptr;
		std::vector<AudioMixer*> m_children{};
		std::vector<AudioSource*> m_sources{};
		float m_volume = 1.0f;
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_MIXER_HPP
