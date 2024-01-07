#ifndef GAM703_ENGINE_AUDIO_AUDIO_MIXER_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_MIXER_HPP

#include <engine/audio/Config.hpp>
#include <engine/audio/AudioSource.hpp>

#include <vector>

namespace gam703::engine::audio
{
	/// @brief AudioMixer allows to change the output volume of all attached audio sources
	class ENGINE_AUDIO_API AudioMixer
	{
	public:
		/// @brief Add audio source to audio mixer
		/// @param source The new source to attach
		void addAudioSource(AudioSource* source);

		/// @brief Remove audio source from audio mixer
		/// @param source The source to remove
		void removeAudioSource(AudioSource* source);

		/// @brief Set the audio mixer volume
		/// @param volume The new volume
		void setVolume(float volume);

		/// @brief Get the audio mixer volume
		/// @return The audio mixer volume
		float getVolume() const { return m_volume; }

		/// @brief Get the volume of the audio mixer after being influenced by parent audio mixer
		/// @return The audio mixer volume multiplied by the parent audio mixer output volume if parent != nullptr
		float getOutputVolume() const { return m_parent ? m_parent->getOutputVolume() * m_volume : m_volume; }

		/// @brief Set the parent audio mixer
		/// @param mixer the audio mixer that will influence this audio mixer
		void setParentMixer(AudioMixer* mixer);

	private:
		/// @brief Update audio sources after setting the volume or changing the parent mixer
		void updateAudioSources() const;

		/// @brief The audio mixer influencing this audio mixer
		AudioMixer* m_parent = nullptr;
		/// @brief All audio mixers influenced by this audio mixer
		std::vector<AudioMixer*> m_children{};
		/// @brief All sources influenced by this audio mixer
		std::vector<AudioSource*> m_sources{};
		/// @brief The audio mixer volume goes from [0-1]
		float m_volume = 1.0f;
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_MIXER_HPP
