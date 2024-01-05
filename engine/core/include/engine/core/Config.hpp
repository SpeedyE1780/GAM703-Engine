#ifndef GAM703_ENGINE_CORE_CONFIG_HPP
#define GAM703_ENGINE_CORE_CONFIG_HPP

#ifdef ENGINE_CORE_DLL
#ifdef ENGINE_CORE_EXPORT
#define ENGINE_CORE_API __declspec(dllexport)
#else
#define ENGINE_CORE_API __declspec(dllimport)
#endif
#else
#define ENGINE_CORE_API
#endif // ENGINE_CORE_DLL

#endif // GAM703_ENGINE_CORE_CONFIG_HPP
