#ifndef GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP
#define GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP

#include <engine/audio/Config.hpp>

#include <irrKlang/irrKlang.h>

#include <string>

namespace  gam703::engine::audio
{
	class ENGINE_AUDIO_API AudioEngine
	{
	public:
		AudioEngine();
		~AudioEngine();

		void play(const std::string& audioFile) const;

	private:
		irrklang::ISoundEngine* m_engine = nullptr;
	};
}

#endif // GAM703_ENGINE_AUDIO_AUDIO_ENGINE_HPP
