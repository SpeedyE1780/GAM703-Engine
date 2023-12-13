#ifndef GAM703_ENGINE_CORE_INTERFACES_ICAMERA_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ICAMERA_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IComponent.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API ICamera : public IComponent
	{
	public:
		ICamera(ITransform* transform);
		virtual ~ICamera() = default;
		virtual glm::mat4 GetViewMatrix() const = 0;
		virtual float getFieldOfView() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ICAMERA_HPP
