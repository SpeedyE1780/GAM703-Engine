#ifndef GAM703_ENGINE_GUI_SLIDER_HPP
#define GAM703_ENGINE_GUI_SLIDER_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/IGUIElement.hpp>

#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Slider : public IGUIElement
	{
	public:
		Slider(const std::string& content, float minimum = 0.0f, float maximum = 1.0f);

		float getValue() const { return m_value; }

	protected:
		virtual void renderElement() const override;

	private:
		std::string m_content;
		mutable float m_value;
		float m_minimum;
		float m_maximum;
	};
}

#endif // GAM703_ENGINE_GUI_SLIDER_HPP
