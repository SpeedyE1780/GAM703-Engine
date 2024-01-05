#include <engine/components/Component.hpp>
#include <engine/components/Transform.hpp>

#include <engine/core-interfaces/IEngine.hpp>

namespace gam703::engine::components
{
	Component::Component(Transform* transform) : m_transform(transform)
	{
	}

	core_interface::IEngine* Component::getEngine()
	{
		return m_transform->getEngine();
	}

	const core_interface::IEngine* Component::getEngine() const
	{
		return m_transform->getEngine();
	}

	core_interface::Scene* Component::getScene()
	{
		return m_transform->getScene();
	}

	const core_interface::Scene* Component::getScene() const
	{
		return m_transform->getScene();
	}

} //gam703::engine::components
