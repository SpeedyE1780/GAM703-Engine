#ifndef GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP
#define GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP

#include <engine/audio/AudioSource.hpp>

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <irrklang/ik_EStreamModes.h>

#include <string>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API AudioPlayer : public Component
	{
	public:
		enum class StreamMode
		{
			AutoDetect = irrklang::ESM_AUTO_DETECT,
			Streaming = irrklang::ESM_STREAMING,
			NoStreaming = irrklang::ESM_NO_STREAMING
		};

		AudioPlayer(Transform& transform, const std::string& audioFile);

		void play(bool loop = false) const { m_audioSource.play(loop); }
		void setStreamMode(StreamMode mode) const { m_audioSource.getSoundSource()->setStreamMode(static_cast<irrklang::E_STREAM_MODE>(mode)); }

		virtual AudioPlayer* clone(Transform& transform) const override;

	private:
		AudioPlayer(Transform& transform, audio::AudioSource& audioSource);

		audio::AudioSource& m_audioSource;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP
