#ifndef GAM703_ENGINE_CORE_INPUT_HPP
#define GAM703_ENGINE_CORE_INPUT_HPP

#include <engine/core/Config.hpp>

#include <engine/gui/Window.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gam703::engine::core
{
	class ENGINE_CORE_API Input
	{
	public:
		Input(gui::Window* window);

		bool isKeyPressed(int key);
		void processMouseMovement(double mouseX, double mouseY);
		void processMouseScroll(double scrollOffsetX, double scrollOffsetY);

		double getMouseOffsetX() const { return m_mouseOffsetX; }
		double getMouseOffsetY() const { return m_mouseOffsetY; }

		double getMouseScrollOffsetX() const { return m_mouseScrollOffsetX; }
		double getMouseScrollOffsetY() const { return m_mouseScrollOffsetY; }

		void resetMouseOffset();
		void setCursorMode(int mode);

	private:
		gui::Window* m_window;
		double m_lastMouseX = 0;
		double m_lastMouseY = 0;
		double m_mouseOffsetX = 0;
		double m_mouseOffsetY = 0;
		double m_mouseScrollOffsetX = 0;
		double m_mouseScrollOffsetY = 0;
	};
} //gam703::engine::core

#endif // GAM703_ENGINE_CORE_INPUT_HPP
