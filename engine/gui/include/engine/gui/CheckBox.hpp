#ifndef GAM703_ENGINE_GUI_CHECKBOX_HPP
#define GAM703_ENGINE_GUI_CHECKBOX_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	/// @brief Checkbox on screen
	class ENGINE_GUI_API Checkbox : public GUIElement
	{
	public:
		/// @brief Create a checkbox on the screen
		/// @param label Label written next to check box
		/// @param initialState Initial checkbox state
		Checkbox(const std::string& label, bool initialState = false);

		/// @brief Return if checkbox is checked
		/// @return True if checkbox is checked
		bool isChecked() const { return m_state; }

	protected:
		/// @brief Render the element on the screen
		virtual void renderElement() const override;

	private:
		/// @brief If checkbox is checked or no
		mutable bool m_state;
	};
}

#endif // GAM703_ENGINE_GUI_CHECKBOX_HPP
