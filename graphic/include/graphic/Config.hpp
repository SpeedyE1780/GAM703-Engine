#ifndef GAM703_ENGINE_GRAPHIC_CONFIG_HPP
#define GAM703_ENGINE_GRAPHIC_CONFIG_HPP

#ifdef GRAPHIC_EXPORT
#define GRAPHIC_API __declspec(dllexport)
#else
#define GRAPHIC_API __declspec(dllimport)
#endif


#endif // GAM703_ENGINE_GRAPHIC_CONFIG_HPP
