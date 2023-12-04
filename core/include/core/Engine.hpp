#ifndef GAM703_ENGINE_CORE_ENGINE_HPP
#define GAM703_ENGINE_CORE_ENGINE_HPP

#include <gui/Window.hpp>

#include <string>

namespace gam703::engine::core
{
	class Engine
	{
	public:
		Engine(const std::string& title, int width, int height);
		~Engine();

		gui::Window& getWindow() { return m_window; }
		const gui::Window& getWindow() const { return m_window; }

		void start();

	private:
		gui::Window m_window;
	};
}

#endif // GAM703_ENGINE_CORE_ENGINE_HPP
