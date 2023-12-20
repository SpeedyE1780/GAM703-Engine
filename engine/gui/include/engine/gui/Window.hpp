#ifndef GAM703_ENGINE_GUI_WINDOW_HPP
#define GAM703_ENGINE_GUI_WINDOW_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/IGUIElement.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <string>
#include <vector>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Window
	{
	public:
		Window(const std::string& title, int width, int height);
		~Window();
		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;

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

		void addText(const std::string& text);

		void render() const;

	private:
		GLFWwindow* m_window;
		const std::string m_title;
		std::vector<std::unique_ptr<IGUIElement>> m_elements;
		int m_width;
		int m_height;
	};
} //gam703::engine::gui

#endif // !GAM703_ENGINE_GUI_WINDOW_HPP
