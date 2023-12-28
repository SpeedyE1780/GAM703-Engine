#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core_interface
{
	IComponent::IComponent(Transform* transform) : m_transform(transform)
	{
	}

	IEngine* IComponent::getEngine()
	{
		return m_transform->getEngine();
	}

	const IEngine* IComponent::getEngine() const
	{
		return m_transform->getEngine();
	}

	IScene* IComponent::getScene()
	{
		return m_transform->getScene();
	}

	const IScene* IComponent::getScene() const
	{
		return m_transform->getScene();
	}

} //gam703::engine::components
