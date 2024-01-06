#ifndef GAM703_ENGINE_CORE_INPUT_HPP
#define GAM703_ENGINE_CORE_INPUT_HPP

#include <engine/core/Config.hpp>

#include <engine/gui/Window.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gam703::engine::core
{
	/// @brief Input handles all input in the game
	class ENGINE_CORE_API Input
	{
	public:
		/// @brief Create an Input handler
		/// @param window The window where all the input is captured
		Input(gui::Window& window);

		/// @brief Check if key is pressed
		/// @param key The keyboard key
		/// @return true if the key is pressed
		bool isKeyPressed(int key) const { return m_window.isKeyPressed(key); }

		/// @brief Process mouse movement in the window
		/// @param mouseX The current mouse X position in the window
		/// @param mouseY The current mouse Y position in the window
		void processMouseMovement(double mouseX, double mouseY);

		/// @brief Process mouse scrolling in the window
		/// @param scrollOffsetX The amoount of horizontal scrolling
		/// @param scrollOffsetY The amount of vertical scrolling
		void processMouseScroll(double scrollOffsetX, double scrollOffsetY);

		/// @brief Get the mouse X offset in the frame
		/// @return The mouse X offset in the frame
		double getMouseOffsetX() const { return m_mouseOffsetX; }

		/// @brief Get the mouse Y offset in the frame
		/// @return The mouse Y offset in the frame
		double getMouseOffsetY() const { return m_mouseOffsetY; }

		/// @brief Get the mouse scroll X offset in the frame
		/// @return The mouse scroll X offset in the frame
		double getMouseScrollOffsetX() const { return m_mouseScrollOffsetX; }

		/// @brief Get the mouse scroll Y offset in the frame
		/// @return The mouse scroll Y offset in the frame
		double getMouseScrollOffsetY() const { return m_mouseScrollOffsetY; }

		/// @brief Resets the mouse movement offset between frames
		void resetMouseOffset();

		/// @brief Set the cursor mode in the window
		/// @param mode The current cursor mode (Normal, Hidden, Disabled)
		void setCursorMode(int mode) const { m_window.setCursorMode(mode); }

	private:
		/// @brief The window where all the input is captured
		gui::Window& m_window;
		/// @brief The mouse X position in the previous frame
		double m_lastMouseX = 0;
		/// @brief The mouse Y position in the previous frame
		double m_lastMouseY = 0;
		/// @brief The mouse X offset in the current frame
		double m_mouseOffsetX = 0;
		/// @brief The mouse Y offset in the current frame
		double m_mouseOffsetY = 0;
		/// @brief The mouse X scroll offset in the current frame
		double m_mouseScrollOffsetX = 0;
		/// @brief The mouse Y scroll offset in the current frame
		double m_mouseScrollOffsetY = 0;
	};
} //gam703::engine::core

#endif // GAM703_ENGINE_CORE_INPUT_HPP
