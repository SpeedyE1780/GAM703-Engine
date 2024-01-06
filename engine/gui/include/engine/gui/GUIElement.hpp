#ifndef GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
#define GAM703_ENGINE_GUI_GUI_ELEMENT_HPP

#include <engine/gui/Config.hpp>

#include <string>

namespace gam703::engine::gui
{
	/// @brief Base class of all GUIElement on screen
	class ENGINE_GUI_API GUIElement
	{
	public:
		/// @brief Create a GUIElement on screen
		/// @param label Label of GUIElement
		GUIElement(const std::string& label);
		virtual ~GUIElement() = default;

		/// @brief Set whether or no to render on new line
		/// @param newLine Whether or no element should render on a new line
		void shouldRenderOnNewLine(bool newLine) { m_shouldRenderOnNewLine = newLine; }

		/// @brief Render gui element to the screen on same/or new line
		void render() const;

	protected:
		/// @brief Render gui element to the screen
		virtual void renderElement() const = 0;

		/// @brief Label of GUIElement
		std::string m_label{};

	private:
		/// @brief If element should be rendered on new line
		bool m_shouldRenderOnNewLine = true;
	};
}

#endif // GAM703_ENGINE_GUI_GUI_ELEMENT_HPP
