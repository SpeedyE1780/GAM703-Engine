#include <engine/core/Engine.hpp>

#include <engine/components/AudioPlayer.hpp>

namespace gam703::engine::components
{
	AudioPlayer::AudioPlayer(Transform& transform, audio::AudioSource& audioSource) : Component(transform), m_audioSource(audioSource)
	{
	}

	AudioPlayer::AudioPlayer(Transform& transform, const std::string& audioFile) : AudioPlayer(transform, *getEngine().getAudioEngine().getAudioSource(audioFile))
	{
	}

	AudioPlayer* AudioPlayer::clone(Transform& transform) const
	{
		return new AudioPlayer(transform, m_audioSource);
	}
}
