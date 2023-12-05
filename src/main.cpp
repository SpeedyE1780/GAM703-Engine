#include <iostream>
#include <core/Engine.hpp>

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	gam703::engine::core::Engine engine("GAM703", 1280, 720);
	engine.start();
	return 0;
}