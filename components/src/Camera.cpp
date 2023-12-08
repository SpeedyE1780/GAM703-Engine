#include <components/Camera.hpp>
#include <components/Transform.hpp>

namespace gam703::engine::components
{
	Camera::Camera(Transform* transform, float yaw, float pitch) : IComponent(transform), m_yaw(yaw), m_pitch(pitch), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM)
	{
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(m_transform->getPosition(), m_transform->getPosition() + m_transform->getFront(), m_transform->getUp());
	}

	void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = m_movementSpeed * deltaTime;

		if (direction == FORWARD)
		{
			m_transform->translate(m_transform->getFront() * velocity);
		}
		if (direction == BACKWARD)
		{
			m_transform->translate(-m_transform->getFront() * velocity);
		}
		if (direction == LEFT)
		{
			m_transform->translate(-m_transform->getRight() * velocity);
		}
		if (direction == RIGHT)
		{
			m_transform->translate(m_transform->getRight() * velocity);
		}
	}

	void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
	{
		xoffset *= m_mouseSensitivity;
		yoffset *= m_mouseSensitivity;

		m_yaw += xoffset;
		m_pitch += yoffset;

		if (constrainPitch)
		{
			m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
		}

		m_transform->setRotation(glm::vec3(glm::radians(m_pitch), glm::radians(m_yaw), 0.0f));
	}

	void Camera::ProcessMouseScroll(float yoffset)
	{
		m_zoom = glm::clamp(m_zoom - yoffset, 1.0f, 45.0f);
	}
}// gam703::engine::components
