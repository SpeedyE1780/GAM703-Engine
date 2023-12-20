#ifndef GAM703_ENGINE_GUI_TEXT_HPP
#define GAM703_ENGINE_GUI_TEXT_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/IGUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Text : public IGUIElement
	{
	public:
		Text(const std::string& content);

		void setContent(const std::string& content) { m_content = content; }

	protected:
		virtual void renderElement() const override;

	private:
		std::string m_content;
	};
}

#endif // GAM703_ENGINE_GUI_TEXT_HPP
