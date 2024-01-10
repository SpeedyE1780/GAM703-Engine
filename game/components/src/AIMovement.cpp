#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>

#include <game/components/AIMovement.hpp>

namespace gam703::game::components
{
	AIMovement::AIMovement(engine::components::Transform& transform, engine::components::Transform* player, const glm::vec3& origin, const glm::vec2& bounds) : 
		engine::components::Behavior(transform),
		m_player(player),
		m_origin(origin),
		m_bounds(bounds),
		m_wander(m_transform, player, origin, bounds),
		m_seek(m_transform, player, &m_wander),
		m_flee(m_transform, player, &m_wander)
	{
		auto* battleStart = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Battle Start.wav");
		battleStart->setAudioMixer(getEngine().getAudioEngine().getAudioMixer("SFX"));
		m_seek.setBattleStart(battleStart);
		m_flee.setBattleStart(battleStart);
		m_wander.setFlee(&m_flee);
		m_wander.setSeek(&m_seek);
		m_currentMovementStrategy = &m_wander;
	}

	AIMovement* AIMovement::clone(engine::components::Transform& transform) const
	{
		return new AIMovement(transform, m_player, m_origin, m_bounds);
	}

	void AIMovement::tick(float deltaTime)
	{
		m_currentMovementStrategy = m_currentMovementStrategy->processMovement(deltaTime);
	}
}
