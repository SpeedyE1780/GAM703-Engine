#include <engine/gui/CheckBox.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	Checkbox::Checkbox(const std::string& content, bool initialState) : m_content(content), m_state(initialState)
	{
	}

	void Checkbox::renderElement() const
	{
		ImGui::Checkbox(m_content.c_str(), &m_state);
	}
}
