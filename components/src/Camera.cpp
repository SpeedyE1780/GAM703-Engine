#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <components/Camera.hpp>
#include <core-interfaces/IEngine.hpp>
#include <core-interfaces/ITransform.hpp>

namespace gam703::engine::components
{
	Camera::Camera(core_interface::ITransform* transform, float yaw, float pitch) : IComponent(transform), m_yaw(yaw), m_pitch(pitch), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM)
	{
	}

	core_interface::IComponent* Camera::clone(core_interface::ITransform* transform) const
	{
		return new Camera(transform, m_yaw, m_pitch);
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(m_transform->getPosition(), m_transform->getPosition() + m_transform->getFront(), m_transform->getUp());
	}

	void Camera::tick(float deltaTime)
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
			m_zoom = glm::clamp(m_zoom - static_cast<float>(inputHandler->getMouseScrollOffsetY()), 1.0f, 45.0f);
		}
	}
}// gam703::engine::components
