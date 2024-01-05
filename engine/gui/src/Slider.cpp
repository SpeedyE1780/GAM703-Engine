#include <engine/gui/Slider.hpp>

#include <imgui/imgui.h>

#include <iostream>

namespace gam703::engine::gui
{
	Slider::Slider(const std::string& label, float minimum, float maximum) : GUIElement(label), m_value(minimum), m_minimum(minimum), m_maximum(maximum)
	{
		if (m_minimum >= m_maximum)
		{
			std::cout << "ERROR MIN GREATER THAN MAX" << std::endl;
		}
	}

	void Slider::renderElement() const
	{
		ImGui::SliderFloat(m_label.c_str(), &m_value, m_minimum, m_maximum);
	}
}
