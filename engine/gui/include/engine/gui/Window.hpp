#ifndef GAM703_ENGINE_GUI_WINDOW_HPP
#define GAM703_ENGINE_GUI_WINDOW_HPP

#include <engine/gui/Config.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Window
	{
	public:
		Window(const std::string& title, int width, int height);

		GLFWwindow* getGLFWWindow() { return m_window; }
		const GLFWwindow* getGLFWWindow() const { return m_window; }

		float getAspectRatio() const { return static_cast<float>(m_width) / static_cast<float>(m_height); }
		std::pair<double, double> getMousePosition() const;
		bool isKeyPressed(int key) const;

		void resizeWindow(int width, int height);
		void setUserData(void* userData);
		void setResizeCallback(GLFWframebuffersizefun callback);
		void setCursorMovementCallback(GLFWcursorposfun callback);
		void setScrollCallback(GLFWcursorposfun callback);
		void setCursorMode(int mode);

	private:
		GLFWwindow* m_window;
		const std::string m_title;
		int m_width;
		int m_height;
	};
} //gam703::engine::gui

#endif // !GAM703_ENGINE_GUI_WINDOW_HPP
