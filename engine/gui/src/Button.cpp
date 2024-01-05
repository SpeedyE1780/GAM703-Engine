#include <engine/gui/Button.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	Button::Button(const std::string& label, std::function<void()> callback) : GUIElement(label), m_callback(move(callback))
	{
	}

	void Button::renderElement() const
	{
		if (ImGui::Button(m_label.c_str()))
		{
			m_callback();
		}
	}
}
