#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/AIMovement.hpp>
#include <game/components/Spawner.hpp>

namespace gam703::game::components
{
	Spawner::Spawner(engine::components::Transform& transform, engine::components::Transform* player, int count, float radius, PowerLevel low, PowerLevel high) :
		engine::components::Component(transform),
		m_player(player),
		m_count(count),
		m_radius(radius),
		m_lowPowerLevel(low),
		m_highPowerLevel(high)
	{
		for (int i = 0; i < count; ++i)
		{
			auto* cylinder = getScene().addTransform(engine::utility::getPointInCircle(radius, m_transform.getPosition()));
			int power = getPowerBetweenLevels(low, high);
			cylinder->addBehavior<AIMovement>(player->getReference(), m_transform.getPosition(), glm::vec2(m_transform.getScale().x * 0.5f, m_transform.getScale().z * 0.5f), power);
			auto* renderer = cylinder->addComponent<engine::components::Renderer>(getEngine().getResourceManager().getModel("resources/Models/cylinder/cylinder.obj"));
			renderer->getMaterial().setColor(getPowerColor(power));
		}
	}

	Spawner* Spawner::clone(engine::components::Transform& transform) const
	{
		return new Spawner(transform, m_player, m_count, m_radius, m_lowPowerLevel, m_highPowerLevel);
	}
}
