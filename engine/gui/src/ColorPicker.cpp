#include <engine/gui/ColorPicker.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	ColorPicker::ColorPicker(const std::string& label) : GUIElement(label)
	{
	}

	void ColorPicker::renderElement() const
	{
		ImGui::ColorEdit4(m_label.c_str(), m_colors);
	}
}
