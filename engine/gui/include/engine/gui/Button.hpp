#ifndef GAM703_ENGINE_GUI_BUTTON_HPP
#define GAM703_ENGINE_GUI_BUTTON_HPP

#include <engine/gui/Config.hpp>
#include <engine/gui/IGUIElement.hpp>

#include <functional>
#include <string>

namespace gam703::engine::gui
{
	class ENGINE_GUI_API Button : public IGUIElement
	{
	public:
		Button(const std::string& context, std::function<void()> callback);

	protected:
		virtual void renderElement() const override;

	private:
		std::string m_content;
		std::function<void()> m_callback;
	};
}

#endif // GAM703_ENGINE_GUI_BUTTON_HPP
