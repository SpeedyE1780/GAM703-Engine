#include <components/Transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

namespace gam703::engine::components
{
	Transform::Transform(core_interface::IEngine* engine, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) : m_position(position), m_rotation(rotation), m_scale(scale), m_transformMatrix(glm::mat4(1)), m_shouldCalculateTransform(true), m_shouldUpdateDirectionVectors(true), m_engine(engine)
	{
		calculateTransformMatrix();
	}

	void Transform::calculateTransformMatrix()
	{
		if (m_shouldCalculateTransform)
		{
			m_transformMatrix = glm::mat4(1);
			m_transformMatrix = glm::translate(m_transformMatrix, m_position);
			m_transformMatrix = m_transformMatrix * glm::toMat4(glm::quat(m_rotation));
			m_transformMatrix = glm::scale(m_transformMatrix, m_scale);
			updateDirectionVectors();
			m_shouldCalculateTransform = false;
		}
	}

	void Transform::updateDirectionVectors()
	{
		if (m_shouldUpdateDirectionVectors)
		{
			glm::vec3 front(
				cos(m_rotation.y) * cos(m_rotation.x),
				sin(m_rotation.x),
				sin(m_rotation.y) * cos(m_rotation.x)
			);

			m_front = glm::normalize(front);
			m_right = glm::normalize(glm::cross(m_front, glm::vec3(0, 1, 0)));
			m_up = glm::normalize(glm::cross(m_right, m_front));

			m_shouldUpdateDirectionVectors = false;
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

	void Transform::setRotation(const glm::vec3& eulerAngles)
	{
		if (m_rotation != eulerAngles)
		{
			m_rotation = eulerAngles;
			m_shouldCalculateTransform = true;
			m_shouldUpdateDirectionVectors = true;
		}
	}

	void Transform::setRotation(float x, float y, float z)
	{
		setRotation(glm::vec3(x, y, z));
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

	void Transform::rotate(const glm::vec3& eulerAngles)
	{
		if (eulerAngles.x != 0 || eulerAngles.y != 0 || eulerAngles.z != 0)
		{
			setRotation(m_rotation + eulerAngles);
		}
	}

	void Transform::rotate(float x, float y, float z)
	{
		rotate(glm::vec3(x, y, z));
	}
}
