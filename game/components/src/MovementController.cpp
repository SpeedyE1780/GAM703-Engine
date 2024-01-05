#include <engine/core/Engine.hpp>
#include <engine/components/Transform.hpp>

#include <game/components/MovementController.hpp>

#include <GLFW/glfw3.h>

namespace gam703::game::components
{
	MovementController::MovementController(engine::components::Transform& transform) : engine::components::Behavior(transform),
		m_pitch(glm::degrees(transform.getRotation().x)),
		m_yaw(glm::degrees(transform.getRotation().y))
	{
	}

	MovementController* MovementController::clone(engine::components::Transform& transform) const
	{
		return new MovementController(transform);
	}

	void MovementController::tick(float deltaTime)
	{
		if (auto* inputHandler = getEngine().getInput())
		{
			float velocity = m_movementSpeed * deltaTime;

			if (inputHandler->isKeyPressed(GLFW_KEY_W))
			{
				m_transform.translate(glm::vec3(0.0f, 0.0f, -1.0f) * velocity);
			}

			if (inputHandler->isKeyPressed(GLFW_KEY_S))
			{
				m_transform.translate(glm::vec3(0.0f, 0.0f, 1.0f) * velocity);
			}

			if (inputHandler->isKeyPressed(GLFW_KEY_A))
			{
				m_transform.translate(glm::vec3(-1.0f, 0.0f, 0.0f) * velocity);
			}

			if (inputHandler->isKeyPressed(GLFW_KEY_D))
			{
				m_transform.translate(glm::vec3(1.0f, 0.0f, 0.0f) * velocity);
			}

			float xoffset = inputHandler->getMouseOffsetX() * m_mouseSensitivity;
			float yoffset = inputHandler->getMouseOffsetY() * m_mouseSensitivity;

			//m_yaw += xoffset;
			//m_pitch += yoffset;

			//m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);

			m_transform.setRotation(glm::vec3(glm::radians(m_pitch), glm::radians(m_yaw), 0.0f));
		}
	}
}
