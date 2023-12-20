#include <engine/gui/ColorPicker.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	ColorPicker::ColorPicker(const std::string& content) : m_content(content)
	{
	}

	void ColorPicker::renderElement() const
	{
		ImGui::ColorEdit4("clear color", m_colors);
	}
}
