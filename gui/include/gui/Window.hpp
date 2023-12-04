#ifndef GAM703_ENGINE_GUI_WINDOW_HPP
#define GAM703_ENGINE_GUI_WINDOW_HPP

#include <GLFW/glfw3.h>

#include <string>

namespace gam703::engine::gui
{
	class Window
	{
	public:
		Window(const std::string& title, int width, int height);
		~Window();
		void resizeWindow(int width, int height);

		void render();

	private:
		GLFWwindow* m_window;
		const std::string m_title;
		int m_width;
		int m_height;
	};
} //gam703::engine::gui

#endif // !GAM703_ENGINE_GUI_WINDOW_HPP
