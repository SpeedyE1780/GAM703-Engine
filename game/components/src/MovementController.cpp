#include <engine/core/Engine.hpp>
#include <engine/components/Transform.hpp>

#include <game/components/FollowTarget.hpp>
#include <game/components/MovementController.hpp>

#include <GLFW/glfw3.h>

namespace gam703::game::components
{
	constexpr float SlowDownPowerDuration = 2.0f;
	constexpr float SlowDownPowerCoolDown = 30.0f;
	constexpr float PowerIndicatorScale = 0.2f;

	MovementController::MovementController(engine::components::Transform& transform) : engine::components::Behavior(transform)
	{
		m_bell = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/bell.wav");
		m_bell->setAudioMixer(getEngine().getAudioEngine().getAudioMixer("SFX"));

		m_renderer = m_transform.getComponent<engine::components::Renderer>();
		m_renderer->getMaterial().setColor(getPowerColor(m_power));

		m_powerIndicator = getScene().addTransform()->getReference();
		m_powerIndicator->addBehavior<FollowTarget>(m_transform.getReference(), glm::vec3(0.0f, 1.5f, 0.0f), m_movementSpeed);
		m_powerIndicator->setScale(glm::vec3(PowerIndicatorScale, PowerIndicatorScale, PowerIndicatorScale));
		auto* renderer = m_powerIndicator->addComponent<engine::components::Renderer>(getEngine().getResourceManager().getModel("resources/Models/cube/cube.obj"));
		renderer->getMaterial().setColor(glm::vec3(0.0f, 0.0f, 1.0f));
	}

	MovementController* MovementController::clone(engine::components::Transform& transform) const
	{
		return new MovementController(transform);
	}

	void MovementController::updatePosition()
	{
		float unscaledDeltaTime = getEngine().getTime().getUnscaledDeltaTime();
		auto& inputHandler = getEngine().getInput();
		float velocity = m_movementSpeed * unscaledDeltaTime;
		glm::vec3 movement{ 0.0f, 0.0f, 0.0f };

		if (inputHandler.isKeyPressed(GLFW_KEY_W))
		{
			movement.z = -1.0f;
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_S))
		{
			movement.z = 1.0f;
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_A))
		{
			movement.x = -1.0f;
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_D))
		{
			movement.x = 1.0f;
		}

		if (movement .x != 0 || movement.z != 0)
		{
			m_transform.translate(glm::normalize(movement) * velocity);
		}
	}

	void MovementController::tick(float deltaTime)
	{
		updatePosition();

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

		if (m_slowDownCooldown < 0.0f && !m_slowDownActive)
		{
			m_powerIndicator->setScale(PowerIndicatorScale, PowerIndicatorScale, PowerIndicatorScale);
		}

		if (inputHandler.isKeyPressed(GLFW_KEY_SPACE) && m_slowDownCooldown <= 0)
		{
			m_bell->play();
			m_slowDownDuration = SlowDownPowerDuration;
			m_slowDownActive = true;
			getEngine().getTime().setTimeScale(0.2f);
			m_powerIndicator->setScale(0.0f, 0.0f, 0.0f);
		}
	}

	void MovementController::increasePower(int power)
	{
		m_power += power;
		m_renderer->getMaterial().setColor(getPowerColor(m_power));
	}
}
