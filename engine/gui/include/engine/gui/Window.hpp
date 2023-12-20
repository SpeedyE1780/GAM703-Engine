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

		std::pair<double, double> getMousePosition() const;
		void resizeWindow(int width, int height);

		float getAspectRatio() const { return static_cast<float>(m_width) / static_cast<float>(m_height); }
		bool isKeyPressed(int key) const { return glfwGetKey(m_window, key) == GLFW_PRESS; }
		void setUserData(void* userData) { glfwSetWindowUserPointer(m_window, userData); }
		void setResizeCallback(GLFWframebuffersizefun callback) { glfwSetFramebufferSizeCallback(m_window, callback); }
		void setCursorMovementCallback(GLFWcursorposfun callback) { glfwSetCursorPosCallback(m_window, callback); }
		void setScrollCallback(GLFWcursorposfun callback) { glfwSetScrollCallback(m_window, callback); }
		void setCursorMode(int mode) { glfwSetInputMode(m_window, GLFW_CURSOR, mode); }
		void swapBuffers() { glfwSwapBuffers(m_window); }

		template<typename Element, typename... Args>
		Element* addGUIElement(Args&&... args)
		{
			auto* element = new Element(std::forward<Args>(args)...);
			m_elements.emplace_back(std::unique_ptr<Element>(element));
			return element;
		}

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
