#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>
#include <engine/components/Camera.hpp>
#include <engine/components/Renderer.hpp>

#include <game/components/MovementController.hpp>

#include <iostream>

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	gam703::engine::core::Engine engine("GAM703", 1280, 720);
	auto* resourceManager = engine.getResourceManager();
	const gam703::engine::core_interface::IModel* ourModel = resourceManager->getModel("resources/Models/backpack/backpack.obj");
	const gam703::engine::core_interface::IModel* ourModel2 = resourceManager->getModel("resources/Models/cube/cube.obj");

	auto* scene = engine.getScene();

	auto* backpackTransform = scene->addTransform(glm::vec3(0.0f, 0.0f, 0.0f));
	backpackTransform->addComponent<gam703::engine::components::Renderer>(ourModel);

	auto* backpackTransform2 = scene->addTransform(backpackTransform);
	backpackTransform2->setPosition(glm::vec3(1.0f, 1.0f, 0.0f));

	auto* cube = scene->addTransform(glm::vec3(2.0f, 2.0f, 0.0f));
	auto* cubeRenderer = cube->addComponent<gam703::engine::components::Renderer>(ourModel2);
	cubeRenderer->getShader()->setColor(glm::vec3(0, 1, 1));

	auto* cube2 = scene->addTransform(cube);
	cube2->setPosition(glm::vec3(3.0f, 3.0f, 0.0f));

	auto* cameraTransform = scene->addTransform(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0, glm::radians(-90.0f), 0));
	auto* camera = cameraTransform->addComponent<gam703::engine::components::Camera>();
	cameraTransform->addComponent<gam703::game::components::MovementController>();

	scene->setActiveCamera(camera);

	engine.start();
	return 0;
}