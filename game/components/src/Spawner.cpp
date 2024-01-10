#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/AIMovement.hpp>
#include <game/components/Spawner.hpp>

namespace gam703::game::components
{
	Spawner::Spawner(engine::components::Transform& transform, engine::components::Transform* player, int count, float radius) : engine::components::Component(transform), m_player(player), m_count(count), m_radius(radius)
	{
		for (int i = 0; i < count; ++i)
		{
			float angle = engine::utility::generateRandomNumber(0.0f, 2.0f * 3.14f);
			auto direction = glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle));
			float distance = engine::utility::generateRandomNumber(0.5f, radius);

			auto* cylinder = getScene().addTransform(direction * distance + m_transform.getPosition());
			cylinder->addBehavior<AIMovement>(player, m_transform.getPosition(), glm::vec2(m_transform.getScale().x * 0.5f, m_transform.getScale().z * 0.5f));
			auto* renderer = cylinder->addComponent<engine::components::Renderer>(getEngine().getResourceManager().getModel("resources/Models/cylinder/cylinder.obj"));
			renderer->getMaterial().setColor(glm::vec3(1.0f, 1.0f, 0.0f));
		}
	}

	Spawner* Spawner::clone(engine::components::Transform& transform) const
	{
		return new Spawner(transform, m_player, m_count, m_radius);
	}
}
