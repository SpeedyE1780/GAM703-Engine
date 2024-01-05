#ifndef GAM703_ENGINE_GUI_CONFIG_HPP
#define GAM703_ENGINE_GUI_CONFIG_HPP

#ifdef ENGINE_GUI_DLL
#ifdef ENGINE_GUI_EXPORT
#define ENGINE_GUI_API __declspec(dllexport)
#else
#define ENGINE_GUI_API __declspec(dllimport)
#endif
#else
#define ENGINE_GUI_API
#endif // ENGINE_GUI_DLL

#endif // GAM703_ENGINE_GUI_CONFIG_HPP
