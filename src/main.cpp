#include <core/Engine.hpp>

#include <components/Transform.hpp>

#include <iostream>

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	gam703::engine::core::Engine engine("GAM703", 1280, 720);
	auto* resourceManager = engine.getResourceManager();
	const gam703::engine::core_interface::IModel* ourModel = resourceManager->getModel("resources/Models/backpack/backpack.obj");
	const gam703::engine::core_interface::IModel* ourModel2 = resourceManager->getModel("resources/Models/backpack/backpack.obj");
	const gam703::engine::core_interface::IModel* ourModel3 = resourceManager->getModel("resources/Models/backpack/backpack.obj");
	const gam703::engine::core_interface::IModel* ourModel4 = resourceManager->getModel("resources/Models/backpack/backpack.obj");

	auto* scene = engine.getScene();

	gam703::engine::components::Transform* backpackTransform = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(0.0f, 0.0f, 0.0f)));
	backpackTransform->addComponent<gam703::engine::components::Renderer>(ourModel);

	gam703::engine::components::Transform* backpackTransform2 = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(1.0f, 1.0f, 0.0f)));
	backpackTransform2->addComponent<gam703::engine::components::Renderer>(ourModel2);

	gam703::engine::components::Transform* backpackTransform3 = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(2.0f, 2.0f, 0.0f)));
	backpackTransform3->addComponent<gam703::engine::components::Renderer>(ourModel3);

	gam703::engine::components::Transform* backpackTransform4 = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(3.0f, 3.0f, 0.0f)));
	backpackTransform4->addComponent<gam703::engine::components::Renderer>(ourModel4);

	engine.start();
	return 0;
}