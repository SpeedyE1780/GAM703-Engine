#ifndef GAM703_ENGINE_GUI_CONFIG_HPP
#define GAM703_ENGINE_GUI_CONFIG_HPP

#ifdef GUI_EXPORT
#define GUI_API __declspec(dllexport)
#else
#define GUI_API __declspec(dllimport)
#endif

#endif // GAM703_ENGINE_GUI_CONFIG_HPP
