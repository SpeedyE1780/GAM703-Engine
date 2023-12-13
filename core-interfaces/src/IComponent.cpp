#include <core-interfaces/IComponent.hpp>
#include <core-interfaces/IEngine.hpp>
#include <core-interfaces/ITransform.hpp>

namespace gam703::engine::core_interface
{
	IComponent::IComponent(ITransform* transform) : m_transform(transform)
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
