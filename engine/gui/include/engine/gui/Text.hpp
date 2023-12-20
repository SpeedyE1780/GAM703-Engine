#ifndef GAM703_ENGINE_GUI_TEXT_HPP
#define GAM703_ENGINE_GUI_TEXT_HPP

#include <engine/gui/IGUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class Text : public IGUIElement
	{
	public:
		Text(const std::string& content);

		virtual void renderElement() const override;

	private:
		std::string m_content;
	};
}

#endif // GAM703_ENGINE_GUI_TEXT_HPP
