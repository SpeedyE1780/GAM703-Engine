#include <core-interfaces/IComponent.hpp>
#include <core-interfaces/IEngine.hpp>
#include <core-interfaces/ITransform.hpp>

namespace gam703::engine::core_interface
{
	IComponent::IComponent(ITransform* transform) : m_transform(transform)
	{
	}

	core_interface::IEngine* IComponent::getEngine()
	{
		return m_transform->getEngine();
	}

	const core_interface::IEngine* IComponent::getEngine() const
	{
		return m_transform->getEngine();
	}
} //gam703::engine::components
