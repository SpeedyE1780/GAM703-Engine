#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	MovementStrategy::MovementStrategy(engine::components::Transform& transform, engine::components::TransformReference player, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower) :
		m_transform(transform),
		m_player(player),
		m_origin(origin),
		m_bounds(bounds),
		m_aiPower(aiPower)
	{
	}
}
