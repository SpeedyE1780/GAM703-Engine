#include <engine/gui/Text.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	Text::Text(const std::string& content) : m_content(content)
	{
	}

	void Text::renderElement() const
	{
		ImGui::Text(m_content.c_str());
	}
}
