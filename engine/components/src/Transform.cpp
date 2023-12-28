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
}
