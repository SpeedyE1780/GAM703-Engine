#include <engine/core-interfaces/ICamera.hpp>

namespace gam703::engine::core_interface
{
	ICamera::ICamera(ITransform* transform) : IComponent(transform)
	{
	}
}
