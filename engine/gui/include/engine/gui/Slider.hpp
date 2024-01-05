#ifndef GAM703_ENGINE_GUI_SLIDER_HPP
#define GAM703_ENGINE_GUI_SLIDER_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Slider : public GUIElement
	{
	public:
		Slider(const std::string& label, float minimum = 0.0f, float maximum = 1.0f);

		float getValue() const { return m_value; }

	protected:
		virtual void renderElement() const override;

	private:
		mutable float m_value;
		float m_minimum;
		float m_maximum;
	};
}

#endif // GAM703_ENGINE_GUI_SLIDER_HPP
