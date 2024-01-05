#ifndef GAM703_ENGINE_GUI_TEXT_HPP
#define GAM703_ENGINE_GUI_TEXT_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Text : public GUIElement
	{
	public:
		Text(const std::string& label);

		void setContent(const std::string& label) { m_label = label; }

	protected:
		virtual void renderElement() const override;

	private:
	};
}

#endif // GAM703_ENGINE_GUI_TEXT_HPP
