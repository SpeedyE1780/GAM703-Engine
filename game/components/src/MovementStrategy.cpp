#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	MovementStrategy::MovementStrategy(engine::components::Transform& transform) : m_transform(transform)
	{
	}
}
