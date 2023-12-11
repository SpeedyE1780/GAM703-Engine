#ifndef GAM703_ENGINE_COMPONENTS_ICOMPONENT_HPP
#define GAM703_ENGINE_COMPONENTS_ICOMPONENT_HPP

#include <components/Config.hpp>
#include <components/Transform.fwd.hpp>
#include <core-interfaces/IEngine.hpp>

namespace gam703::engine::components
{
	class COMPONENTS_API IComponent
	{
	public:
		IComponent(Transform* transform);
		virtual ~IComponent() = default;

		Transform* getTransform() { return m_transform; }
		const Transform* getTransform() const { return m_transform; }

		virtual void tick(float deltaTime) = 0;

		core_interface::IEngine* getEngine();
		const core_interface::IEngine* getEngine() const;

	protected:
		Transform* m_transform;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_ICOMPONENT_HPP
