#ifndef GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
#define GAM703_ENGINE_GUI_GUI_ELEMENT_HPP

#include <engine/gui/Config.hpp>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API IGUIElement
	{
	public:
		virtual ~IGUIElement() = default;

		void shouldRenderOnNewLine(bool newLine) { m_shouldRenderOnNewLine = newLine; }
		void render() const;

	protected:
		virtual void renderElement() const = 0;

	private:
		bool m_shouldRenderOnNewLine = true;
	};
}

#endif // GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
