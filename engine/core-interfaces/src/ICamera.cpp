#include <engine/core-interfaces/ICamera.hpp>
#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/Transform.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace gam703::engine::core_interface
{
	constexpr float MinimumFOV = 1.0f;
	constexpr float MaximumFOV = 120.0f;

	Camera::Camera(Transform* transform) : IComponent(transform)
	{
	}

	Camera::Camera(Transform* transform, float fieldOfView) : IComponent(transform), m_fieldOfView(fieldOfView)
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
		return glm::lookAt(m_transform->getPosition(), m_transform->getPosition() + m_transform->getFront(), m_transform->getUp());
	}

	core_interface::IComponent* Camera::clone(core_interface::Transform* transform) const
	{
		return new Camera(transform, m_fieldOfView);
	}

	void Camera::tick(float deltaTime)
	{
		if (auto* inputHandler = getEngine()->getInput())
		{
			setFieldOfView(glm::clamp(getFieldOfView() - static_cast<float>(inputHandler->getMouseScrollOffsetY()), MinimumFOV, MaximumFOV));
		}
	}
}
