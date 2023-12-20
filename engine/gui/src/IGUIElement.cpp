#include <engine/gui/IGUIElement.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	void IGUIElement::render() const
	{
		if (!m_shouldRenderOnNewLine)
		{
			ImGui::SameLine();
		}

		renderElement();
	}
}
