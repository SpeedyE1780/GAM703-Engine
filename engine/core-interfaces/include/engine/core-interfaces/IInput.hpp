#ifndef GAM703_ENGINE_CORE_INTERFACES_IINPUT_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IINPUT_HPP

namespace gam703::engine::core_interface
{
	class IInput
	{
	public:
		virtual ~IInput() = default;
		virtual bool isKeyPressed(int key) = 0;
		virtual void processMouseMovement(double mouseX, double mouseY) = 0;
		virtual void processMouseScroll(double scrollOffsetX, double scrollOffsetY) = 0;
		virtual double getMouseOffsetX() const = 0;
		virtual double getMouseOffsetY() const = 0;
		virtual double getMouseScrollOffsetX() const = 0;
		virtual double getMouseScrollOffsetY() const = 0;
		virtual void resetMouseOffset() = 0;
		virtual void setCursorMode(int mode) = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IINPUT_HPP
