#include <components/Camera.hpp>

namespace gam703::engine::components
{
	Camera::Camera(Transform* transform, glm::vec3 position, glm::vec3 up, float yaw, float pitch) : IComponent(transform), m_position(position), m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_up(), m_right(), m_worldUp(up), m_yaw(yaw), m_pitch(pitch), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM)
	{
		updateCameraVectors();
	}

	Camera::Camera(Transform* transform, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : IComponent(transform), m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVITY), m_zoom(ZOOM)
	{
		m_position = glm::vec3(posX, posY, posZ);
		m_worldUp = glm::vec3(upX, upY, upZ);
		m_yaw = yaw;
		m_pitch = pitch;
		updateCameraVectors();
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = m_movementSpeed * deltaTime;
		if (direction == FORWARD)
			m_position += m_front * velocity;
		if (direction == BACKWARD)
			m_position -= m_front * velocity;
		if (direction == LEFT)
			m_position -= m_right * velocity;
		if (direction == RIGHT)
			m_position += m_right * velocity;
	}

	void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
	{
		xoffset *= m_mouseSensitivity;
		yoffset *= m_mouseSensitivity;

		m_yaw += xoffset;
		m_pitch += yoffset;

		if (constrainPitch)
		{
			if (m_pitch > 89.0f)
				m_pitch = 89.0f;
			if (m_pitch < -89.0f)
				m_pitch = -89.0f;
		}

		updateCameraVectors();
	}

	void Camera::ProcessMouseScroll(float yoffset)
	{
		m_zoom = glm::clamp(m_zoom - yoffset, 1.0f, 45.0f);
	}

	void Camera::updateCameraVectors()
	{
		glm::vec3 front(
			cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch)),
			sin(glm::radians(m_pitch)),
			sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch))
		);
		m_front = glm::normalize(front);
		m_right = glm::normalize(glm::cross(m_front, m_worldUp));
		m_up = glm::normalize(glm::cross(m_right, m_front));
	}

}// gam703::engine::components
