#ifndef GAM703_ENGINE_CORE_INPUT_HPP
#define GAM703_ENGINE_CORE_INPUT_HPP

#include <core/Config.hpp>
#include <core-interfaces/IInput.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gam703::engine::core
{
	class CORE_API Input : public core_interface::IInput
	{
	public:
		Input(GLFWwindow* window);

		virtual bool isKeyPressed(int key) override;
		virtual void processMouseMovement(double mouseX, double mouseY) override;
		virtual void processMouseScroll(double scrollOffsetX, double scrollOffsetY) override;

		virtual double getMouseOffsetX() const override { return m_mouseOffsetX; }
		virtual double getMouseOffsetY() const { return m_mouseOffsetY; }

		virtual double getMouseScrollOffsetX() const override { return m_mouseScrollOffsetX; }
		virtual double getMouseScrollOffsetY() const override { return m_mouseScrollOffsetY; }

		virtual void resetMouseOffset() override;

	private:
		GLFWwindow* m_window;
		double m_lastMouseX = 0;
		double m_lastMouseY = 0;
		double m_mouseOffsetX = 0;
		double m_mouseOffsetY = 0;
		double m_mouseScrollOffsetX = 0;
		double m_mouseScrollOffsetY = 0;
	};
} //gam703::engine::core

#endif // GAM703_ENGINE_CORE_INPUT_HPP
