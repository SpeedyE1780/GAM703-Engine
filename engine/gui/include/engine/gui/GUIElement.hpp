#ifndef GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
#define GAM703_ENGINE_GUI_GUI_ELEMENT_HPP

#include <engine/gui/Config.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API GUIElement
	{
	public:
		GUIElement(const std::string& label);
		virtual ~GUIElement() = default;

		void shouldRenderOnNewLine(bool newLine) { m_shouldRenderOnNewLine = newLine; }
		void render() const;

	protected:
		virtual void renderElement() const = 0;

		std::string m_label{};

	private:
		bool m_shouldRenderOnNewLine = true;
	};
}

#endif // GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
