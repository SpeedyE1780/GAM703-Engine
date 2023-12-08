#include <components/Transform.hpp>
#include <glm/gtx/quaternion.hpp>

namespace gam703::engine::components
{
	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : m_position(position), m_rotation(rotation), m_scale(scale), m_transformMatrix(glm::mat4(1)), m_shouldCalculateTransform(true)
	{
		calculateTransformMatrix();
	}

	void Transform::calculateTransformMatrix()
	{
		if (m_shouldCalculateTransform)
		{
			m_transformMatrix = glm::mat4(1);
			m_transformMatrix = glm::translate(m_transformMatrix, m_position);
			m_transformMatrix = m_transformMatrix * glm::toMat4(m_rotation);
			m_transformMatrix = glm::scale(m_transformMatrix, m_scale);
			m_shouldCalculateTransform = false;
		}
	}

	void Transform::setPosition(const glm::vec3& position)
	{
		m_position = position;
		m_shouldCalculateTransform = true;
	}

	void Transform::setPosition(float x, float y, float z)
	{
		m_position = glm::vec3(x, y, z);
		m_shouldCalculateTransform = true;
	}

	void Transform::setRotation(const glm::quat& rotation)
	{
		m_rotation = rotation;
		m_shouldCalculateTransform = true;
	}

	void Transform::setRotation(const glm::vec3& eulerAngles)
	{
		m_rotation = glm::quat(eulerAngles);
		m_shouldCalculateTransform = true;
	}

	void Transform::setRotation(float x, float y, float z)
	{
		m_rotation = glm::quat(1, x, y, z);
		m_shouldCalculateTransform = true;
	}

	void Transform::setScale(const glm::vec3& scale)
	{
		m_scale = scale;
		m_shouldCalculateTransform = true;
	}

	void Transform::setScale(float x, float y, float z)
	{
		m_scale = glm::vec3(x, y, z);
		m_shouldCalculateTransform = true;
	}
}
