#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/ITransform.hpp>

#include <game/components/MovementController.hpp>

#include <GLFW/glfw3.h>

namespace gam703::game::components
{
	MovementController::MovementController(engine::core_interface::ITransform* transform) : engine::core_interface::IComponent(transform)
	{
	}

	engine::core_interface::IComponent* MovementController::clone(engine::core_interface::ITransform* transform) const
	{
		return new MovementController(*this);
	}

	void MovementController::tick(float deltaTime)
	{
		if (auto* inputHandler = getEngine()->getInput())
		{
			float velocity = m_movementSpeed * deltaTime;

			if (inputHandler->isKeyPressed(GLFW_KEY_W))
			{
				m_transform->translate(m_transform->getFront() * velocity);
			}

			if (inputHandler->isKeyPressed(GLFW_KEY_S))
			{
				m_transform->translate(-m_transform->getFront() * velocity);
			}

			if (inputHandler->isKeyPressed(GLFW_KEY_A))
			{
				m_transform->translate(-m_transform->getRight() * velocity);
			}

			if (inputHandler->isKeyPressed(GLFW_KEY_D))
			{
				m_transform->translate(m_transform->getRight() * velocity);
			}

			float xoffset = inputHandler->getMouseOffsetX() * m_mouseSensitivity;
			float yoffset = inputHandler->getMouseOffsetY() * m_mouseSensitivity;

			m_yaw += xoffset;
			m_pitch += yoffset;

			m_pitch = glm::clamp(m_pitch + yoffset, -89.0f, 89.0f);

			m_transform->setRotation(glm::vec3(glm::radians(m_pitch), glm::radians(m_yaw), 0.0f));
		}
	}
}
