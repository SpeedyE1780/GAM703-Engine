#include <engine/gui/Text.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	Text::Text(const std::string& label) : GUIElement(label)
	{
	}

	void Text::renderElement() const
	{
		ImGui::Text(m_label.c_str());
	}
}
