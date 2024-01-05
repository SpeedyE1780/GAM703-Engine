#ifndef GAM703_ENGINE_COMPONENTS_COMPONENT_HPP
#define GAM703_ENGINE_COMPONENTS_COMPONENT_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Transform.fwd.hpp>

#include <engine/core/Engine.fwd.hpp>

#include <engine/core/Scene.fwd.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Component
	{
	public:
		Component(Transform& transform);
		virtual ~Component() = default;

		virtual Component* clone(Transform& transform) const = 0;

		Transform& getTransform() { return m_transform; }
		const Transform& getTransform() const { return m_transform; }

		core::Engine& getEngine();
		const core::Engine& getEngine() const;

		core::Scene& getScene();
		const core::Scene& getScene() const;

	protected:
		Transform& m_transform;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_COMPONENT_HPP
