#ifndef GAM703_ENGINE_GUI_COLOR_PICKER_HPP
#define GAM703_ENGINE_GUI_COLOR_PICKER_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API ColorPicker : public GUIElement
	{
	public:
		ColorPicker(const std::string& content);

		std::tuple<float, float, float, float> getColors() const { return { m_colors[0], m_colors[1], m_colors[2], m_colors[3] }; }

	protected:
		virtual void renderElement() const override;

	private:
		mutable float m_colors[4] = { 1, 1, 1, 1 };

	};
}

#endif // GAM703_ENGINE_GUI_COLOR_PICKER_HPP
