#ifndef GAM703_ENGINE_CORE_INPUT_HPP
#define GAM703_ENGINE_CORE_INPUT_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gam703::engine::core
{
	class Input
	{
	public:
		Input(GLFWwindow* window);

		bool isKeyPressed(int key);
		void processMouseMovement(double mouseX, double mouseY);

		double getMouseOffsetX() const { return m_mouseOffsetX; }
		double getMouseOffsetY() const { return m_mouseOffsetY; }

		void resetMouseOffset();

	private:
		GLFWwindow* m_window;
		double m_lastMouseX = 0;
		double m_lastMouseY = 0;
		double m_mouseOffsetX = 0;
		double m_mouseOffsetY = 0;
	};
} //gam703::engine::core

#endif // GAM703_ENGINE_CORE_INPUT_HPP
