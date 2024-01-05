#include <engine/components/Camera.hpp>
#include <engine/components/Transform.hpp>

#include <engine/core/Scene.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace gam703::engine::components
{
	constexpr float MinimumFOV = 1.0f;
	constexpr float MaximumFOV = 120.0f;

	Camera::Camera(Transform& transform) : Component(transform)
	{
	}

	Camera::Camera(Transform& transform, float fieldOfView) : Component(transform), m_fieldOfView(fieldOfView)
	{
	}

	void Camera::setFieldOfView(float fieldOfView)
	{
		if (m_fieldOfView != fieldOfView)
		{
			m_fieldOfView = fieldOfView;
			getScene()->updateSceneProjectionMatrix();
		}
	}

	glm::mat4 Camera::getViewMatrix() const
	{
		return glm::lookAt(m_transform.getPosition(), m_transform.getPosition() + m_transform.getFront(), m_transform.getUp());
	}

	Camera* Camera::clone(Transform& transform) const
	{
		return new Camera(transform, m_fieldOfView);
	}
}
