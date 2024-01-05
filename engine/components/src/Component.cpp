#include <engine/components/Component.hpp>
#include <engine/components/Transform.hpp>

namespace gam703::engine::components
{
	Component::Component(Transform& transform) : m_transform(transform)
	{
	}

	core::Engine& Component::getEngine()
	{
		return m_transform.getEngine();
	}

	const core::Engine& Component::getEngine() const
	{
		return m_transform.getEngine();
	}

	core::Scene* Component::getScene()
	{
		return m_transform.getScene();
	}

	const core::Scene* Component::getScene() const
	{
		return m_transform.getScene();
	}

} //gam703::engine::components
