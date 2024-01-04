#include <engine/core-interfaces/Transform.hpp>

#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <algorithm>

namespace gam703::engine::core_interface
{
	Transform::Transform(IEngine* engine, IScene* scene, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) :
		m_engine(engine),
		m_scene(scene),
		m_position(position),
		m_rotation(rotation),
		m_scale(scale)
	{
		calculateTransformMatrix();
	}

	Transform::Transform(const Transform& transform) : 
		m_engine(transform.m_engine),
		m_scene(transform.m_scene),
		m_position(transform.m_position),
		m_rotation(transform.m_rotation),
		m_scale(transform.m_scale),
		m_front(transform.m_front),
		m_up(transform.m_front),
		m_right(transform.m_right),
		m_transformMatrix(transform.m_transformMatrix),
		m_normalMatrix(transform.m_normalMatrix),
		m_shouldCalculateTransform(transform.m_shouldCalculateTransform),
		m_shouldUpdateDirectionVectors(transform.m_shouldUpdateDirectionVectors)
	{
		std::for_each(begin(transform.m_components), end(transform.m_components), [this](const std::unique_ptr<Component>& component)
			{
				m_components.push_back(std::unique_ptr<Component>(component->clone(this)));
			});

		std::for_each(begin(transform.m_behaviors), end(transform.m_behaviors), [this](const std::unique_ptr<Behavior>& behavior)
			{
				m_behaviors.push_back(std::unique_ptr<Behavior>(behavior->clone(this)));
			});
	}

	Transform& Transform::operator=(const Transform& transform)
	{
		m_engine = transform.m_engine;
		m_scene = transform.m_scene;
		m_position = transform.m_position;
		m_rotation = transform.m_rotation;
		m_scale = transform.m_scale;
		m_front = transform.m_front;
		m_up = transform.m_front;
		m_right = transform.m_right;
		m_transformMatrix = transform.m_transformMatrix;
		m_normalMatrix = transform.m_normalMatrix;
		m_shouldCalculateTransform = transform.m_shouldCalculateTransform;
		m_shouldUpdateDirectionVectors = transform.m_shouldUpdateDirectionVectors;
		m_components = std::vector<std::unique_ptr<Component>>{};

		std::for_each(begin(transform.m_components), end(transform.m_components), [this](const std::unique_ptr<Component>& component)
			{
				m_components.push_back(std::unique_ptr<Component>(component->clone(this)));
			});

		std::for_each(begin(transform.m_behaviors), end(transform.m_behaviors), [this](const std::unique_ptr<Behavior>& behavior)
			{
				m_behaviors.push_back(std::unique_ptr<Behavior>(behavior->clone(this)));
			});

		return *this;
	}

	Transform* Transform::clone() const
	{
		return new Transform(*this);
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

	void Transform::calculateTransformMatrix()
	{
		if (m_shouldCalculateTransform)
		{
			m_transformMatrix = glm::mat4(1);
			m_transformMatrix = glm::translate(m_transformMatrix, m_position);
			m_transformMatrix = m_transformMatrix * glm::toMat4(glm::quat(m_rotation));
			m_transformMatrix = glm::scale(m_transformMatrix, m_scale);
			m_normalMatrix = glm::mat3(glm::transpose(glm::inverse(m_transformMatrix)));
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

	void Transform::updateBehaviors(float deltaTime)
	{
		std::for_each(begin(m_behaviors), end(m_behaviors), [deltaTime](std::unique_ptr<Behavior>& behavior) { behavior->tick(deltaTime); });
	}
}
