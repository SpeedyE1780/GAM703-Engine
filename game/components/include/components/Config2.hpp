#ifndef GAM703_GAME_COMPONENTS_CONFIG_HPP
#define GAM703_GAME_COMPONENTS_CONFIG_HPP

#ifdef GAME_COMPONENTS_EXPORT
#define GAME_COMPONENTS_API __declspec(dllexport)
#else
#define GAME_COMPONENTS_API __declspec(dllimport)
#endif

#endif // GAM703_GAME_COMPONENTS_CONFIG_HPP
