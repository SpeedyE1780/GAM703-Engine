#ifndef GAM703_ENGINE_GUI_COLOR_PICKER_HPP
#define GAM703_ENGINE_GUI_COLOR_PICKER_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	/// @brief ColorPicker on screen
	class ENGINE_GUI_API ColorPicker : public GUIElement
	{
	public:
		/// @brief Create a color picker on the screen
		/// @param label Label written next to color picker
		ColorPicker(const std::string& label);

		/// @brief Get the current color
		/// @return A tuple to enable structure binding (eg: auto [r, g, b, a] = getColors())
		std::tuple<float, float, float, float> getColors() const { return { m_colors[0], m_colors[1], m_colors[2], m_colors[3] }; }

	protected:
		/// @brief Render the element on the screen
		virtual void renderElement() const override;

	private:
		/// @brief Current color selected
		mutable float m_colors[4] = { 1, 1, 1, 1 };

	};
}

#endif // GAM703_ENGINE_GUI_COLOR_PICKER_HPP
