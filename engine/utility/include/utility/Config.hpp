#ifndef GAM703_ENGINE_UTILITY_CONFIG_HPP
#define GAM703_ENGINE_UTILITY_CONFIG_HPP

#ifdef UTILITY_EXPORT
#define UTILITY_API __declspec(dllexport)
#else
#define UTILITY_API __declspec(dllimport)
#endif

#endif // GAM703_ENGINE_UTILITY_CONFIG_HPP
