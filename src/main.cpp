#include <core/Engine.hpp>

#include <components/Transform.hpp>
#include <components/Camera.hpp>

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

	auto* backpackTransform = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(0.0f, 0.0f, 0.0f)));
	backpackTransform->addComponent<gam703::engine::components::Renderer>(ourModel);

	auto* backpackTransform2 = scene->addTransform(backpackTransform);
	backpackTransform2->setPosition(glm::vec3(1.0f, 1.0f, 0.0f));

	auto* backpackTransform3 = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(2.0f, 2.0f, 0.0f)));
	backpackTransform3->addComponent<gam703::engine::components::Renderer>(ourModel3);

	auto* backpackTransform4 = scene->addTransform(backpackTransform3);
	backpackTransform4->setPosition(glm::vec3(3.0f, 3.0f, 0.0f));

	auto* cameraTransform = dynamic_cast<gam703::engine::components::Transform*>(scene->addTransform(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0, glm::radians(-90.0f), 0)));
	auto* camera = cameraTransform->addComponent<gam703::engine::components::Camera>();

	engine.setMainCamera(camera);

	engine.start();
	return 0;
}