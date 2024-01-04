#include <engine/core-interfaces/Component.hpp>
#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core_interface
{
	Component::Component(Transform* transform) : m_transform(transform)
	{
	}

	IEngine* Component::getEngine()
	{
		return m_transform->getEngine();
	}

	const IEngine* Component::getEngine() const
	{
		return m_transform->getEngine();
	}

	Scene* Component::getScene()
	{
		return m_transform->getScene();
	}

	const Scene* Component::getScene() const
	{
		return m_transform->getScene();
	}

} //gam703::engine::components
