#include <engine/core/Engine.hpp>
#include <engine/components/Transform.hpp>

#include <game/components/MovementController.hpp>

#include <GLFW/glfw3.h>

namespace gam703::game::components
{
	constexpr float SlowDownPowerDuration = 2.0f;
	constexpr float SlowDownPowerCoolDown = 30.0f;

	MovementController::MovementController(engine::components::Transform& transform) : engine::components::Behavior(transform)
	{
		m_bell = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/bell.wav");
		m_bell->setAudioMixer(getEngine().getAudioEngine().getAudioMixer("SFX"));

		m_renderer = m_transform.getComponent<engine::components::Renderer>();
		m_renderer->getMaterial().setColor(getPowerColor(m_power));
	}

	MovementController* MovementController::clone(engine::components::Transform& transform) const
	{
		return new MovementController(transform);
	}

	void MovementController::tick(float deltaTime)
	{
		float unscaledDeltaTime = getEngine().getTime().getUnscaledDeltaTime();
		auto& inputHandler = getEngine().getInput();
		float velocity = m_movementSpeed * unscaledDeltaTime;

		m_slowDownDuration -= unscaledDeltaTime;
		m_slowDownCooldown -= unscaledDeltaTime;

		if (m_slowDownDuration < 0 && m_slowDownActive)
		{
			getEngine().getTime().setTimeScale(1.0f);
			m_bell->play();
			m_slowDownActive = false;
			m_slowDownCooldown = SlowDownPowerCoolDown;
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_W))
		{
			m_transform.translate(glm::vec3(0.0f, 0.0f, -1.0f) * velocity);
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_S))
		{
			m_transform.translate(glm::vec3(0.0f, 0.0f, 1.0f) * velocity);
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_A))
		{
			m_transform.translate(glm::vec3(-1.0f, 0.0f, 0.0f) * velocity);
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_D))
		{
			m_transform.translate(glm::vec3(1.0f, 0.0f, 0.0f) * velocity);
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_SPACE) && m_slowDownCooldown <= 0)
		{
			m_bell->play();
			m_slowDownDuration = SlowDownPowerDuration;
			m_slowDownActive = true;
			getEngine().getTime().setTimeScale(0.2f);
		}
	}

	void MovementController::increasePower(int power)
	{
		m_power += power;
		m_renderer->getMaterial().setColor(getPowerColor(m_power));
	}
}
