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
		if (m_position != position)
		{
			m_position = position;
			m_shouldCalculateTransform = true;
		}
	}

	void Transform::setPosition(float x, float y, float z)
	{
		setPosition(glm::vec3(x, y, z));
	}

	void Transform::setRotation(const glm::quat& rotation)
	{
		if (m_rotation != rotation)
		{
			m_rotation = rotation;
			m_shouldCalculateTransform = true;
		}
	}

	void Transform::setRotation(const glm::vec3& eulerAngles)
	{
		setRotation(glm::quat(eulerAngles));
	}

	void Transform::setRotation(float x, float y, float z)
	{
		setRotation(glm::quat(1, x, y, z));
	}

	void Transform::setScale(const glm::vec3& scale)
	{
		if (m_scale != scale)
		{
			m_scale = scale;
			m_shouldCalculateTransform = true;
		}
	}

	void Transform::setScale(float x, float y, float z)
	{
		setScale(glm::vec3(x, y, z));
	}

	void Transform::translate(const glm::vec3& offset)
	{
		if (offset.x != 0 || offset.y != 0 || offset.z != 0)
		{
			setPosition(m_position + offset);
		}
	}

	void Transform::translate(float x, float y, float z)
	{
		translate(glm::vec3(x, y, z));
	}

	void Transform::rotate(const glm::quat& quaternion)
	{
		if (quaternion.x != 0 || quaternion.y != 0 || quaternion.z != 0)
		{
			setRotation(m_rotation * quaternion);
		}
	}

	void Transform::rotate(const glm::vec3& eulerAngles)
	{
		rotate(glm::quat(eulerAngles));
	}

	void Transform::rotate(float x, float y, float z)
	{
		rotate(glm::quat(1, x, y, z));
	}
}
