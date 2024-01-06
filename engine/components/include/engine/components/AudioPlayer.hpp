#ifndef GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP
#define GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP

#include <engine/audio/AudioSource.hpp>

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <string>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API AudioPlayer : public Component
	{
	public:
		AudioPlayer(Transform& transform, const std::string& audioFile);

		void play() { m_audioSource.play(); }

		virtual AudioPlayer* clone(Transform& transform) const override;

	private:
		AudioPlayer(Transform& transform, audio::AudioSource& audioSource);

		audio::AudioSource& m_audioSource;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP
