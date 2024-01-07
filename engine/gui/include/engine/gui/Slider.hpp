#ifndef GAM703_ENGINE_GUI_SLIDER_HPP
#define GAM703_ENGINE_GUI_SLIDER_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	/// @brief Slider on screen
	class ENGINE_GUI_API Slider : public GUIElement
	{
	public:
		/// @brief Create a slider on the screen
		/// @param label Label next to slider
		/// @param minimum Minimum value of slider
		/// @param maximum Maximum value of slider
		Slider(const std::string& label, float minimum = 0.0f, float maximum = 1.0f);

		/// @brief Get current slider value
		/// @return The current slider value
		float getValue() const { return m_value; }

	protected:
		/// @brief Render the element on the screen
		virtual void renderElement() const override;

	private:
		/// @brief Current slider value
		mutable float m_value;
		/// @brief Minimum slider value
		float m_minimum;
		/// @brief Maximum slider value
		float m_maximum;
	};
}

#endif // GAM703_ENGINE_GUI_SLIDER_HPP
