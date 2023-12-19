#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>
#include <engine/components/Camera.hpp>
#include <engine/components/Renderer.hpp>

#include <game/components/MovementController.hpp>
#include <game/components/Wonder.hpp>

#include <iostream>

namespace engine = gam703::engine;
namespace game = gam703::game;

static engine::core_interface::ITransform* addGroundPlane(engine::core_interface::IEngine& engine,
	const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
	const glm::vec3& mainColor = glm::vec3(1.0f, 1.0f, 1.0f),
	const glm::vec3& secondColor = glm::vec3(0.0f, 0.0f, 0.0f))
{
	const engine::core_interface::IModel* backpackModel = engine.getResourceManager()->getModel("resources/Models/backpack/backpack.obj");
	const engine::core_interface::IModel* cubeModel = engine.getResourceManager()->getModel("resources/Models/cube/cube.obj");
	engine::graphic::Shader checkeredShader{ "resources/Shaders/Default.vert", "resources/Shaders/Checkermap.frag" };

	auto* backpack = engine.getScene()->addTransform(position + glm::vec3(0.0f, 2.1f, 0.0f));
	backpack->addComponent<engine::components::Renderer>(backpackModel);
	backpack->addComponent<game::components::Wonder>();

	auto* cube = engine.getScene()->addTransform(position, glm::vec3(), glm::vec3(5.0f, 0.1f, 5.0f));
	auto* renderer = cube->addComponent<engine::components::Renderer>(cubeModel, checkeredShader);
	renderer->getMaterial()->setColor(mainColor);
	renderer->getMaterial()->getShader()->setVec3("secondColor", secondColor);

	return cube;
}

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	engine::core::Engine engine("GAM703", 1280, 720);

	addGroundPlane(engine);
	addGroundPlane(engine, glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	addGroundPlane(engine, glm::vec3(-10.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	addGroundPlane(engine, glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	addGroundPlane(engine, glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	auto* scene = engine.getScene();
	auto* cameraTransform = scene->addTransform(glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(glm::radians(-45.0f), glm::radians(-90.0f), 0));
	auto* camera = cameraTransform->addComponent<engine::components::Camera>();
	//cameraTransform->addComponent<gam703::game::components::MovementController>();

	auto* cubeModel = engine.getResourceManager()->getModel("resources/Models/cube/cube.obj");
	auto* cubeTransform = scene->addTransform(glm::vec3(0.0f, 1.1f, 0.0f));
	auto* renderer = cubeTransform->addComponent<engine::components::Renderer>(cubeModel);
	renderer->getMaterial()->setColor(glm::vec3(0.0f, 0.0f, 1.0f));
	cubeTransform->addComponent<game::components::MovementController>();

	scene->setActiveCamera(camera);

	engine.start();
	return 0;
}
