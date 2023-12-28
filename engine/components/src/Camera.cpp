#include <engine/components/Camera.hpp>

#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Transform.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::components
{
	constexpr float MinimumFOV = 1.0f;
	constexpr float MaximumFOV = 120.0f;

	Camera::Camera(core_interface::Transform* transform) : core_interface::ICamera(transform)
	{
	}

	core_interface::IComponent* Camera::clone(core_interface::Transform* transform) const
	{
		return new Camera(transform);
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(m_transform->getPosition(), m_transform->getPosition() + m_transform->getFront(), m_transform->getUp());
	}

	void Camera::setFieldOfView(float fieldOfView)
	{
		if (m_fieldOfView != fieldOfView)
		{
			m_fieldOfView = fieldOfView;
			getScene()->updateSceneProjectionMatrix();
		}
	}

	void Camera::tick(float deltaTime)
	{
		if (auto* inputHandler = getEngine()->getInput())
		{
			setFieldOfView(glm::clamp(m_fieldOfView - static_cast<float>(inputHandler->getMouseScrollOffsetY()), MinimumFOV, MaximumFOV));
		}
	}
}// gam703::engine::components
