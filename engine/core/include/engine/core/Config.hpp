#ifndef GAM703_ENGINE_CORE_CONFIG_HPP
#define GAM703_ENGINE_CORE_CONFIG_HPP

#ifdef ENGINE_CORE_EXPORT
#define ENGINE_CORE_API __declspec(dllexport)
#else
#define ENGINE_CORE_API __declspec(dllimport)
#endif

#endif // GAM703_ENGINE_CORE_CONFIG_HPP
