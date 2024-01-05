#ifndef GAM703_ENGINE_AUDIO_CONFIG_HPP
#define GAM703_ENGINE_AUDIO_CONFIG_HPP

#ifdef ENGINE_AUDIO_DLL
#ifdef ENGINE_AUDIO_EXPORT
#define ENGINE_AUDIO_API __declspec(dllexport)
#else
#define ENGINE_AUDIO_API __declspec(dllimport)
#endif // ENGINE_AUDIO_EXPORT
#else
#define ENGINE_AUDIO_API
#endif // ENGINE_AUDIO_DLL

#endif // GAM703_ENGINE_AUDIO_CONFIG_HPP
