#ifndef GAM703_ENGINE_GUI_COLOR_PICKER_HPP
#define GAM703_ENGINE_GUI_COLOR_PICKER_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/IGUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API ColorPicker : public IGUIElement
	{
	public:
		ColorPicker(const std::string& content);

		virtual void renderElement() const override;

		std::tuple<float, float, float, float> getColors() const { return { m_colors[0], m_colors[1], m_colors[2], m_colors[3] }; }

	private:
		std::string m_content;
		mutable float m_colors[4] = { 1, 1, 1, 1 };

	};
}

#endif // GAM703_ENGINE_GUI_COLOR_PICKER_HPP
