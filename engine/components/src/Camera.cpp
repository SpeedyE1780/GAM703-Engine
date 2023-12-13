#include <glm/glm.hpp>
#include <components/Camera.hpp>
#include <core-interfaces/IEngine.hpp>
#include <core-interfaces/ITransform.hpp>

namespace gam703::engine::components
{
	Camera::Camera(core_interface::ITransform* transform) : core_interface::ICamera(transform)
	{
	}

	core_interface::IComponent* Camera::clone(core_interface::ITransform* transform) const
	{
		return new Camera(transform);
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(m_transform->getPosition(), m_transform->getPosition() + m_transform->getFront(), m_transform->getUp());
	}

	void Camera::tick(float deltaTime)
	{
		if (auto* inputHandler = getEngine()->getInput())
		{
			m_fieldOfView = glm::clamp(m_fieldOfView - static_cast<float>(inputHandler->getMouseScrollOffsetY()), 1.0f, 45.0f);
		}
	}
}// gam703::engine::components
