#include <core/Input.hpp>

namespace gam703::engine::core
{
	Input::Input(GLFWwindow* window) : m_window(window)
	{
	}

	bool Input::isKeyPressed(int key)
	{
		return m_window ? glfwGetKey(m_window, key) == GLFW_PRESS : nullptr;
	}

} //gam703::engine::core
