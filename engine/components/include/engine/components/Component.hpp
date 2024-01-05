#ifndef GAM703_ENGINE_COMPONENTS_COMPONENT_HPP
#define GAM703_ENGINE_COMPONENTS_COMPONENT_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Transform.fwd.hpp>

#include <engine/core-interfaces/IEngine.fwd.hpp>
#include <engine/core-interfaces/Scene.fwd.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Component
	{
	public:
		Component(Transform* transform);
		virtual ~Component() = default;

		virtual Component* clone(Transform* transform) const = 0;

		Transform* getTransform() { return m_transform; }
		const Transform* getTransform() const { return m_transform; }

		core_interface::IEngine* getEngine();
		const core_interface::IEngine* getEngine() const;

		core_interface::Scene* getScene();
		const core_interface::Scene* getScene() const;

	protected:
		Transform* m_transform;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_COMPONENT_HPP
