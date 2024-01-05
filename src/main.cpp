#include <engine/core/Engine.hpp>

#include <engine/components/Camera.hpp>
#include <engine/components/DirectionalLight.hpp>
#include <engine/components/PointLight.hpp>
#include <engine/components/Renderer.hpp>
#include <engine/components/SpotLight.hpp>
#include <engine/components/Transform.hpp>

#include <engine/gui/Button.hpp>
#include <engine/gui/Checkbox.hpp>
#include <engine/gui/ColorPicker.hpp>
#include <engine/gui/Slider.hpp>
#include <engine/gui/Text.hpp>

#include <game/components/MovementController.hpp>
#include <game/components/Wonder.hpp>

#include <iostream>
#include <format>

namespace engine = gam703::engine;
namespace game = gam703::game;

static engine::components::Transform* addGroundPlane(engine::core::Engine& engine,
	engine::components::Transform* player,
	const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
	const glm::vec3& mainColor = glm::vec3(1.0f, 1.0f, 1.0f),
	const glm::vec3& secondColor = glm::vec3(0.0f, 0.0f, 0.0f))
{
	const engine::graphic::Model* backpackModel = engine.getResourceManager().getModel("resources/Models/backpack/backpack.obj");
	const engine::graphic::Model* cubeModel = engine.getResourceManager().getModel("resources/Models/cube/cube.obj");
	engine::graphic::Shader checkeredShader{ "resources/Shaders/Default.vert", "resources/Shaders/Checkermap.frag" };

	auto* backpack = engine.getScene().addTransform(position + glm::vec3(0.0f, 2.1f, 0.0f));
	backpack->addComponent<engine::components::Renderer>(backpackModel);
	backpack->addBehavior<game::components::Wonder>(player);

	auto* cube = engine.getScene().addTransform(position, glm::vec3(), glm::vec3(5.0f, 0.1f, 5.0f));
	auto* renderer = cube->addComponent<engine::components::Renderer>(cubeModel, checkeredShader);
	renderer->getMaterial().setColor(mainColor);
	renderer->getMaterial().getShader()->setVec3("secondColor", secondColor);

	return cube;
}

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	engine::core::Engine engine("GAM703", 1280, 720);
	auto& scene = engine.getScene();


	auto* cubeModel = engine.getResourceManager().getModel("resources/Models/cube/cube.obj");
	auto* playerTransform = scene.addTransform(glm::vec3(0.0f, 1.1f, 0.0f));
	auto* renderer = playerTransform->addComponent<engine::components::Renderer>(cubeModel);
	renderer->getMaterial().setColor(glm::vec3(0.0f, 0.0f, 1.0f));
	playerTransform->addBehavior<game::components::MovementController>();

	addGroundPlane(engine, playerTransform);
	addGroundPlane(engine, playerTransform, glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	addGroundPlane(engine, playerTransform, glm::vec3(-10.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	addGroundPlane(engine, playerTransform, glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	addGroundPlane(engine, playerTransform, glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	auto* cameraTransform = scene.addTransform(glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(glm::radians(-45.0f), glm::radians(-90.0f), 0));
	auto* camera = cameraTransform->addComponent<engine::components::Camera>();
	//cameraTransform->addComponent<gam703::game::components::MovementController>();

	scene.setActiveCamera(camera);

	auto* directionalLightTransform = scene.addTransform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(glm::radians(-90.f), 0.0f, 0.0f));
	auto* directionalLight = directionalLightTransform->addComponent < engine::components::DirectionalLight>(glm::vec3(1.0f, 1.0f, 1.0f), 1.0f);

	auto* pointLightTransform = scene.addTransform(glm::vec3(0.0f, 30.0f, 0.0f));
	pointLightTransform->addComponent<engine::components::Renderer>(cubeModel);
	auto* pointLight = pointLightTransform->addComponent<engine::components::PointLight>(glm::vec3(1.0f, 0.0f, 0.0f), 5.0f, 5.0f);

	auto* spotLightTransform = scene.addTransform(glm::vec3(10.0f, 30.0f, 0.0f), glm::vec3(glm::radians(-90.0f), 0.0f, 0.0f));
	spotLightTransform->addComponent < engine::components::Renderer>(cubeModel);
	auto* spotLight = spotLightTransform->addComponent<engine::components::SpotLight>(glm::vec3(0.0f, 0.0f, 1.0f));

	auto& window = engine.getWindow();
	window.addGUIElement<engine::gui::Text>("This is some useful text.");
	auto* demo = window.addGUIElement<engine::gui::Checkbox>("Demo Window", true);
	auto* another = window.addGUIElement<engine::gui::Checkbox>("Another Window", false);
	auto* slider = window.addGUIElement<engine::gui::Slider>("Float");
	auto* pointLightHeight = window.addGUIElement<engine::gui::Slider>("pointLightHeight", 0.0f, 30.0f);
	auto* colorPicker = window.addGUIElement<engine::gui::ColorPicker>("COLOR");
	int counter = 0;
	engine::gui::Text* text = nullptr;

	window.addGUIElement<engine::gui::Button>("BUTTON", [&counter, &text, &scene, colorPicker, slider, pointLightHeight, pointLightTransform, spotLightTransform]()
		{
			counter++;
			text->setContent(std::format("counter: {}", counter));
			auto [r, g, b, a] = colorPicker->getColors();
			scene.getSceneRenderer()->setAmbientLight(glm::vec3(r, g, b), slider->getValue());

			pointLightTransform->setPosition(glm::vec3(0.0f, pointLightHeight->getValue(), 0.0f));
			spotLightTransform->setPosition(glm::vec3(10.0f, pointLightHeight->getValue(), 0.0f));
		});

	text = window.addGUIElement<engine::gui::Text>(std::format("counter: {}", counter));
	text->shouldRenderOnNewLine(false);

	engine.start();

	std::cout << "DEMO: " << (demo->isChecked() ? "TRUE" : "FALSE") << " ANOTHER: " << (another->isChecked() ? "TRUE" : "FALSE") << std::endl;
	return 0;
}
