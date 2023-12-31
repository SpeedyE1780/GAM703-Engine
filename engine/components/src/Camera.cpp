#include <engine/components/Camera.hpp>

#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Transform.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::components
{
	Camera::Camera(core_interface::Transform* transform) : core_interface::Camera(transform)
	{
	}

}// gam703::engine::components
