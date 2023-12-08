#include <components/IComponent.hpp>

namespace gam703::engine::components
{
	IComponent::IComponent(Transform* transform) : m_transform(transform)
	{
	}
} //gam703::engine::components
