#include <engine/gui/CheckBox.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	Checkbox::Checkbox(const std::string& label, bool initialState) : GUIElement(label), m_state(initialState)
	{
	}

	void Checkbox::renderElement() const
	{
		ImGui::Checkbox(m_label.c_str(), &m_state);
	}
}
