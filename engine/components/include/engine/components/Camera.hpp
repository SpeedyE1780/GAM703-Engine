#ifndef GAM703_ENGINE_COMPONENTS_CAMERA_HPP
#define GAM703_ENGINE_COMPONENTS_CAMERA_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/ICamera.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace gam703::engine::components
{

	class ENGINE_COMPONENTS_API Camera : public core_interface::Camera
	{
	public:
		Camera(core_interface::Transform* transform);
	};

} //gam703::engine::components

#endif //GAM703_ENGINE_COMPONENTS_CAMERA_HPP
