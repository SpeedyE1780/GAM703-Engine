#ifndef GAM703_ENGINE_GUI_WINDOW_HPP
#define GAM703_ENGINE_GUI_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <graphic/Model.hpp>
#include <graphic/Shader.hpp>
#include <components/Camera.hpp>
#include <string>

namespace gam703::engine::gui
{
	class Window
	{
	public:
		Window(const std::string& title, int width, int height);
		void resizeWindow(int width, int height);

		void render(const components::Camera& sceneCamera, const graphic::Shader& shader, const graphic::Model& model) const;

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
