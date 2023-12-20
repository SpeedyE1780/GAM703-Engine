#include <engine/gui/Button.hpp>

#include <imgui/imgui.h>

namespace gam703::engine::gui
{
	Button::Button(const std::string& content, std::function<void()> callback) : m_content(content), m_callback(move(callback))
	{
	}

	void Button::renderElement() const
	{
		if (ImGui::Button(m_content.c_str()))
		{
			m_callback();
		}
	}
}
