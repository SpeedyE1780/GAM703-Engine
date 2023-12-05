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

	private:
		GLFWwindow* m_window;
	};
} //gam703::engine::core

#endif // GAM703_ENGINE_CORE_INPUT_HPP
