#include <components/IComponent.hpp>
#include <components/Transform.hpp>

namespace gam703::engine::components
{
	IComponent::IComponent(Transform* transform) : m_transform(transform)
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
