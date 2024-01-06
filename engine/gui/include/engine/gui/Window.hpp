#ifndef GAM703_ENGINE_GUI_WINDOW_HPP
#define GAM703_ENGINE_GUI_WINDOW_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>

#include <memory>
#include <string>
#include <vector>

namespace gam703::engine::gui
{
	/// @brief Window that wraps GLFW window
	class ENGINE_GUI_API Window
	{
	public:
		/// @brief Create glfw window
		/// @param title Window title
		/// @param width Window width
		/// @param height Window height
		Window(const std::string& title, int width, int height);

		/// @brief Close GLFW window
		~Window();

		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;

		/// @brief Get GLFW window
		/// @return GLFW Window
		GLFWwindow* getGLFWWindow() { return m_window; }

		/// @brief Get GLFW window
		/// @return GLFW Window
		const GLFWwindow* getGLFWWindow() const { return m_window; }

		/// @brief Get mouse position on screen
		/// @return Mouse Position x y pair
		std::pair<double, double> getMousePosition() const;

		/// @brief Resize window
		/// @param width New window width
		/// @param height New window height
		void resizeWindow(int width, int height);

		/// @brief Get window aspect ratio
		/// @return Window aspect ratio
		float getAspectRatio() const { return static_cast<float>(m_width) / static_cast<float>(m_height); }

		/// @brief Check if key is pressed
		/// @param key Key on the keyboard
		/// @return True if key is pressed
		bool isKeyPressed(int key) const { return glfwGetKey(m_window, key) == GLFW_PRESS; }

		/// @brief Set GLFW window user data
		/// @param userData GLFW window user data to be retrieved using GLFW window in C callbacks
		void setUserData(void* userData) { glfwSetWindowUserPointer(m_window, userData); }

		/// @brief Set window resize callback
		/// @param callback Callback that will be called on resize event
		void setResizeCallback(GLFWframebuffersizefun callback) { glfwSetFramebufferSizeCallback(m_window, callback); }

		/// @brief Set cursor movement callback
		/// @param callback Callback that will be called when cursor moves in window
		void setCursorMovementCallback(GLFWcursorposfun callback) { glfwSetCursorPosCallback(m_window, callback); }

		/// @brief Set scroll callback
		/// @param callback Callback that will be called when the window is scrolled
		void setScrollCallback(GLFWcursorposfun callback) { glfwSetScrollCallback(m_window, callback); }

		/// @brief Set the cursor mode
		/// @param mode The cursor mode (Normal, Hidden, Disabled)
		void setCursorMode(int mode) { glfwSetInputMode(m_window, GLFW_CURSOR, mode); }

		/// @brief Swap the GLFW window buffers
		void swapBuffers() { glfwSwapBuffers(m_window); }

		/// @brief Add gui element to window
		/// @tparam Element The type of the new element
		/// @tparam ...Args Expands to Element constructor's argument
		/// @param ...args All the argument needed to construct the Element
		/// @return The newly added element
		template<typename Element, typename... Args>
		Element* addGUIElement(Args&&... args)
		{
			auto* element = new Element(std::forward<Args>(args)...);
			m_elements.emplace_back(std::unique_ptr<GUIElement>(element));
			return element;
		}

		/// @brief Render all gui elements to window
		/// @param context The current IMGUI context
		void render(ImGuiContext* context) const;

	private:
		/// @brief GLFW window being wrapped
		GLFWwindow* m_window;
		/// @brief Window title
		const std::string m_title;
		/// @brief Lists of gui elements
		std::vector<std::unique_ptr<GUIElement>> m_elements;
		/// @brief Window width
		int m_width;
		/// @brief Window height
		int m_height;
	};
} //gam703::engine::gui

#endif // !GAM703_ENGINE_GUI_WINDOW_HPP
