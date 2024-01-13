#ifndef GAM703_ENGINE_GUI_BUTTON_HPP
#define GAM703_ENGINE_GUI_BUTTON_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <functional>
#include <string>

namespace gam703::engine::gui
{
	/// @brief Button on screen
	class ENGINE_GUI_API Button : public GUIElement
	{
	public:
		/// @brief Create a button on the screen
		/// @param label Label written on button
		/// @param callback Function called once button is pressed
		Button(const std::string& label, std::function<void()> callback);

	protected:
		/// @brief Render the element on the screen
		virtual void renderElement() const override;

	private:
		/// @brief Callback called once button is pressed
		std::function<void()> m_callback;
	};
}

#endif // GAM703_ENGINE_GUI_BUTTON_HPP
