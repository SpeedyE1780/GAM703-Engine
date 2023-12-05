#include <core/Input.hpp>

namespace gam703::engine::core
{
	Input::Input(GLFWwindow* window) : m_window(window)
	{
		if (m_window)
		{
			glfwGetCursorPos(m_window, &m_lastMouseX, &m_lastMouseY);
		}
	}

	bool Input::isKeyPressed(int key)
	{
		return m_window ? glfwGetKey(m_window, key) == GLFW_PRESS : nullptr;
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

	void Input::resetMouseOffset()
	{
		m_mouseOffsetX = 0;
		m_mouseOffsetY = 0;
	}

} //gam703::engine::core
