#ifndef GAM703_ENGINE_GUI_WINDOW_HPP
#define GAM703_ENGINE_GUI_WINDOW_HPP

#include <components/Camera.hpp>
#include <components/Renderer.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gui/Config.hpp>

#include <string>

namespace gam703::engine::gui
{
	class GUI_API Window
	{
	public:
		Window(const std::string& title, int width, int height);
		void resizeWindow(int width, int height);

		void render(const components::Camera& sceneCamera, const components::Renderer& renderer) const;

		GLFWwindow* getGLFWWindow() { return m_window; }
		const GLFWwindow* getGLFWWindow() const { return m_window; }

	private:
		GLFWwindow* m_window;
		const std::string m_title;
		int m_width;
		int m_height;
	};
} //gam703::engine::gui

#endif // !GAM703_ENGINE_GUI_WINDOW_HPP
