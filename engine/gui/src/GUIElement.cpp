#include <engine/gui/GUIElement.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	GUIElement::GUIElement(const std::string& label) : m_label(label)
	{
	}

	void GUIElement::render() const
	{
		if (!m_shouldRenderOnNewLine)
		{
			ImGui::SameLine();
		}

		renderElement();
	}
}
