#ifndef GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
#define GAM703_ENGINE_GUI_GUI_ELEMENT_HPP

namespace gam703::engine::gui
{
	class IGUIElement
	{
	public:
		virtual ~IGUIElement() = default;

		virtual void renderElement() const = 0;
	};
}

#endif // GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
