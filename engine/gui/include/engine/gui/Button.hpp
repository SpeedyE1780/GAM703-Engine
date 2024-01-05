#ifndef GAM703_ENGINE_GUI_BUTTON_HPP
#define GAM703_ENGINE_GUI_BUTTON_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/GUIElement.hpp>

#include <functional>
#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Button : public GUIElement
	{
	public:
		Button(const std::string& label, std::function<void()> callback);

	protected:
		virtual void renderElement() const override;

	private:
		std::function<void()> m_callback;
	};
}

#endif // GAM703_ENGINE_GUI_BUTTON_HPP
