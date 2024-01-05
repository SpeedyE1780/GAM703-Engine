#include <engine/core/Input.hpp>

namespace gam703::engine::core
{
	Input::Input(gui::Window* window) : m_window(window)
	{
		std::tie(m_lastMouseX, m_lastMouseY) = m_window->getMousePosition();
	}

	void Input::processMouseMovement(double mouseX, double mouseY)
	{
		static bool firstTime = true;

		if (firstTime)
		{
			firstTime = false;
			m_lastMouseX = mouseX;
			m_lastMouseY = mouseY;
		}

		m_mouseOffsetX = mouseX - m_lastMouseX;
		m_mouseOffsetY = m_lastMouseY - mouseY;

		m_lastMouseX = mouseX;
		m_lastMouseY = mouseY;
	}

	void Input::processMouseScroll(double scrollOffsetX, double scrollOffsetY)
	{
		m_mouseScrollOffsetX = scrollOffsetX;
		m_mouseScrollOffsetY = scrollOffsetY;
	}

	void Input::resetMouseOffset()
	{
		m_mouseOffsetX = 0;
		m_mouseOffsetY = 0;
		m_mouseScrollOffsetX = 0;
		m_mouseScrollOffsetY = 0;
	}

} //gam703::engine::core
