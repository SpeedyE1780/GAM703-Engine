#include <engine/components/Transform.hpp>

#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

namespace gam703::engine::components
{
	Transform::Transform(core_interface::IEngine* engine, core_interface::IScene* scene, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) :
		core_interface::ITransform(engine, scene, position, rotation, scale)
	{
	}

	Transform::Transform(const Transform& transform) :
		ITransform(transform)
	{
	}

	Transform& Transform::operator=(const Transform& transform)
	{
		ITransform::operator=(transform);

		return *this;
	}

	core_interface::ITransform* Transform::clone() const
	{
		return new Transform(*this);
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
