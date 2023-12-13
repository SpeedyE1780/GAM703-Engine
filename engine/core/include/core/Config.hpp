#ifndef GAM703_ENGINE_CORE_CONFIG_HPP
#define GAM703_ENGINE_CORE_CONFIG_HPP

#ifdef CORE_EXPORT
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

#endif // GAM703_ENGINE_CORE_CONFIG_HPP
