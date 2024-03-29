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

#include <game/components/AIMovement.hpp>
#include <game/components/FollowTarget.hpp>
#include <game/components/MovementController.hpp>
#include <game/components/PowerLevel.hpp>
#include <game/components/Spawner.hpp>

#include <iostream>
#include <format>

namespace engine = gam703::engine;
namespace game = gam703::game;

constexpr int AreaBounds = 10;

struct SpawnerInfo
{
	game::components::PowerLevel lowLevel;
	game::components::PowerLevel highLevel;
	int enemyCount;
};

static void addGroundPlane(engine::core::Engine& engine, engine::components::Transform* player)
{
	const engine::graphic::Model* planeModel = engine.getResourceManager().getModel("resources/Models/plane/plane.obj");
	engine::graphic::Shader* checkeredShader = engine.getResourceManager().getShader("resources/Shaders/Default.vert", "resources/Shaders/Checkermap.frag");

	auto* plane = engine.getScene().addTransform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(), glm::vec3(AreaBounds, 1.0f, AreaBounds));
	auto* renderer = plane->addComponent<engine::components::Renderer>(planeModel, *checkeredShader);
	renderer->getMaterial().setSecondColor(glm::vec3(0.0f, 0.0f, 0.0f));
}

static void addGroundPlane(engine::core::Engine& engine,
	engine::components::Transform* player,
	SpawnerInfo spawnInfo,
	const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f))
{
	const engine::graphic::Model* planeModel = engine.getResourceManager().getModel("resources/Models/plane/plane.obj");
	engine::graphic::Shader* checkeredShader = engine.getResourceManager().getShader("resources/Shaders/Default.vert", "resources/Shaders/Checkermap.frag");

	auto* plane = engine.getScene().addTransform(position, glm::vec3(), glm::vec3(AreaBounds, 1.0f, AreaBounds));
	plane->addComponent<game::components::Spawner>(player, spawnInfo.enemyCount, AreaBounds * 0.5f, spawnInfo.lowLevel, spawnInfo.highLevel);
	auto* renderer = plane->addComponent<engine::components::Renderer>(planeModel, *checkeredShader);
	renderer->getMaterial().setSecondColor(glm::vec3(0.0f, 0.0f, 0.0f));
}

int main()
{
	std::cout << "GAM703-GameEngine" << std::endl;

	engine::core::Engine engine("GAM703", 1280, 720);
	auto& scene = engine.getScene();

	auto* masterMixer = engine.getAudioEngine().addAudioMixer("Master");
	auto* backgroundMusicMixer = engine.getAudioEngine().addAudioMixer("BM");
	backgroundMusicMixer->setParentMixer(masterMixer);
	engine.getAudioEngine().addAudioMixer("SFX")->setParentMixer(masterMixer);

	auto* cubeModel = engine.getResourceManager().getModel("resources/Models/cube/cube.obj");
	auto* playerTransform = scene.addTransform();
	auto* renderer = playerTransform->addComponent<engine::components::Renderer>(cubeModel);
	renderer->getMaterial().setColor(glm::vec3(0.0f, 0.0f, 1.0f));
	playerTransform->addBehavior<game::components::MovementController>();

	addGroundPlane(engine, playerTransform);
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Stronger, game::components::PowerLevel::Strongest, 18 }, glm::vec3(AreaBounds, 0.0f, 0.0f));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Stronger, game::components::PowerLevel::Strongest, 18 }, glm::vec3(-AreaBounds, 0.0f, 0.0f));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Strong, game::components::PowerLevel::Stronger, 12 }, glm::vec3(0.0f, 0.0f, AreaBounds));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Strong, game::components::PowerLevel::Stronger, 12 }, glm::vec3(0.0f, 0.0f, -AreaBounds));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Normal, game::components::PowerLevel::Strong, 10 }, glm::vec3(-AreaBounds, 0.0f, -AreaBounds));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Weak, game::components::PowerLevel::Normal, 8 }, glm::vec3(AreaBounds, 0.0f, -AreaBounds));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Weaker, game::components::PowerLevel::Weak, 6 }, glm::vec3(AreaBounds, 0.0f, AreaBounds));
	addGroundPlane(engine, playerTransform, { game::components::PowerLevel::Weakest, game::components::PowerLevel::Weaker, 6 }, glm::vec3(-AreaBounds, 0.0f, AreaBounds));

	auto* cameraTransform = scene.addTransform(glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(glm::radians(-45.0f), glm::radians(-90.0f), 0));
	auto* camera = cameraTransform->addComponent<engine::components::Camera>();
	cameraTransform->addBehavior<game::components::FollowTarget>(playerTransform->getReference(), cameraTransform->getPosition());

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
			scene.getSceneRenderer().setAmbientLight(glm::vec3(r, g, b), slider->getValue());

			pointLightTransform->setPosition(glm::vec3(0.0f, pointLightHeight->getValue(), 0.0f));
			spotLightTransform->setPosition(glm::vec3(10.0f, pointLightHeight->getValue(), 0.0f));
		});

	text = window.addGUIElement<engine::gui::Text>(std::format("counter: {}", counter));
	text->shouldRenderOnNewLine(false);

	auto* masterVolume = window.addGUIElement<engine::gui::Slider>("Master Volume");
	auto* backgroundVolume = window.addGUIElement<engine::gui::Slider>("Background Music Volume");
	auto* sfxVolume = window.addGUIElement<engine::gui::Slider>("SFX Volume");

	window.addGUIElement<engine::gui::Button>("Update Mixers", [masterVolume, backgroundVolume, sfxVolume, &engine]()
		{
			auto* master = engine.getAudioEngine().getAudioMixer("Master");
			auto* backgroundMusic = engine.getAudioEngine().getAudioMixer("BM");
			auto* sfx = engine.getAudioEngine().getAudioMixer("SFX");

			master->setVolume(masterVolume->getValue());
			backgroundMusic->setVolume(backgroundVolume->getValue());
			sfx->setVolume(sfxVolume->getValue());
		});

	auto* backgroundMusicPlayer = scene.addTransform()->addComponent<engine::components::AudioPlayer>("resources/Audio/breakout.mp3");
	backgroundMusicPlayer->setStreamMode(engine::components::AudioPlayer::StreamMode::Streaming);
	backgroundMusicPlayer->setAudioMixer(backgroundMusicMixer);
	backgroundMusicPlayer->play(true);

	engine.start();

	std::cout << "DEMO: " << (demo->isChecked() ? "TRUE" : "FALSE") << " ANOTHER: " << (another->isChecked() ? "TRUE" : "FALSE") << std::endl;
	return 0;
}
