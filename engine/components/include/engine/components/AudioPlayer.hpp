#ifndef GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP
#define GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP

#include <engine/audio/AudioSource.hpp>
#include <engine/audio/AudioMixer.fwd.hpp>

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <irrklang/ik_EStreamModes.h>

#include <string>

namespace gam703::engine::components
{
	/// @brief AudioPlayer wraps AudioSource and allows scene objects to play them
	class ENGINE_COMPONENTS_API AudioPlayer : public Component
	{
	public:
		/// @brief The audio file streaming mode
		enum class StreamMode
		{
			/// @brief Automatically decide the best mode
			AutoDetect = irrklang::ESM_AUTO_DETECT,
			/// @brief Streams data when needed
			Streaming = irrklang::ESM_STREAMING,
			/// @brief Load all data in the memory
			NoStreaming = irrklang::ESM_NO_STREAMING
		};

		/// @brief Create an audio player that plays the given audio file
		/// @param transform The transform that owns this component
		/// @param audioFile The file that will be played
		AudioPlayer(Transform& transform, const std::string& audioFile);

		/// @brief Play the audio source
		/// @param loop Loop the audio once it's done playing
		void play(bool loop = false) const { m_audioSource.play(loop); }

		/// @brief Set the audio player stream mode
		/// @param mode The mode that will be used to stream the audio
		void setStreamMode(StreamMode mode) const { m_audioSource.getSoundSource()->setStreamMode(static_cast<irrklang::E_STREAM_MODE>(mode)); }

		/// @brief Set the audio mixer that will influence this audio player
		/// @param mixer The audio mixer influencing this audio player
		void setAudioMixer(audio::AudioMixer* mixer) const { m_audioSource.setAudioMixer(mixer); }

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned AudioPlayer belonging to the transform
		virtual AudioPlayer* clone(Transform& transform) const override;

	private:
		/// @brief Create an audio player referencing the given audio source
		/// @param transform The transform that owns this component
		/// @param audioSource The audio source that this audio player will wrap
		AudioPlayer(Transform& transform, audio::AudioSource& audioSource);

		audio::AudioSource& m_audioSource;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_AUDIO_PLAYER_HPP
