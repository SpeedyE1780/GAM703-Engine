#ifndef GAM703_ENGINE_GUI_TEXT_HPP
#define GAM703_ENGINE_GUI_TEXT_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	/// @brief Text on screen
	class ENGINE_GUI_API Text : public GUIElement
	{
	public:
		/// @brief Create a slider on the screen
		/// @param label Text label
		Text(const std::string& label);

		/// @brief Set text label
		/// @param label Text label
		void setContent(const std::string& label) { m_label = label; }

	protected:
		/// @brief Render element on the screen
		virtual void renderElement() const override;
	};
}

#endif // GAM703_ENGINE_GUI_TEXT_HPP
