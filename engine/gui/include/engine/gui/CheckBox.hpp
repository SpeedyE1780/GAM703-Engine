#ifndef GAM703_ENGINE_GUI_CHECKBOX_HPP
#define GAM703_ENGINE_GUI_CHECKBOX_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/IGUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Checkbox : public IGUIElement
	{
	public:
		Checkbox(const std::string& content, bool initialState = false);

		bool isChecked() const { return m_state; }

	protected:
		virtual void renderElement() const override;

	private:
		std::string m_content;
		mutable bool m_state;
	};
}

#endif // GAM703_ENGINE_GUI_CHECKBOX_HPP
