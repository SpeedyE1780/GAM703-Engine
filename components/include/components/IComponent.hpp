#ifndef GAM703_ENGINE_COMPONENTS_ICOMPONENT_HPP
#define GAM703_ENGINE_COMPONENTS_ICOMPONENT_HPP

#include <components/Config.hpp>
#include <components/Transform.fwd.hpp>

namespace gam703::engine::components
{
	class COMPONENTS_API IComponent
	{
	public:
		IComponent(Transform* transform);
		virtual ~IComponent() = default;

	protected:
		Transform* m_transform;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_ICOMPONENT_HPP
