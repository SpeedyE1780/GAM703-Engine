#include <iostream>
#include <gui/Window.hpp>

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	gam703::engine::gui::Window window("GAM703", 1280, 720);
	window.render();
	return 0;
}