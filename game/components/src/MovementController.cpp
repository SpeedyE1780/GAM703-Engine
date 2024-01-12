#include <engine/core/Engine.hpp>
#include <engine/components/Transform.hpp>

#include <game/components/MovementController.hpp>

#include <GLFW/glfw3.h>

namespace gam703::game::components
{
	MovementController::MovementController(engine::components::Transform& transform) : engine::components::Behavior(transform)
	{
		m_bell = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/bell.wav");
		m_bell->setAudioMixer(getEngine().getAudioEngine().getAudioMixer("SFX"));
	}

	MovementController* MovementController::clone(engine::components::Transform& transform) const
	{
		return new MovementController(transform);
	}

	void MovementController::tick(float deltaTime)
	{
		auto& inputHandler = getEngine().getInput();
		float velocity = m_movementSpeed * deltaTime;

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

		if (inputHandler.isKeyPressed(GLFW_KEY_SPACE))
		{
			m_bell->play();
		}
	}
}
