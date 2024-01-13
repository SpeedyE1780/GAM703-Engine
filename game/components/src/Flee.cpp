#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Flee.hpp>
#include <game/components/MovementController.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	Flee::Flee(engine::components::Transform& transform, const engine::components::TransformReference& player, Wander* wander, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower) :
		MovementStrategy(transform, player, origin, bounds, aiPower),
		m_wander(wander)
	{
		m_fleeStart = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/FleeStart.wav");
		m_fleeEnd = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/FleeEnd.wav");
		auto* sfxMixer = m_transform.getEngine().getAudioEngine().getAudioMixer("SFX");
		m_fleeStart->setAudioMixer(sfxMixer);
		m_fleeEnd->setAudioMixer(sfxMixer);
	}

	void Flee::enter()
	{
		m_fleeStart->play();
	}

	MovementStrategy* Flee::processMovement(float deltaTime)
	{
		if (!m_player)
		{
			return m_wander;
		}

		auto offset = m_transform.getPosition() - m_player->getPosition();
		float distanceToPlayer = glm::length(offset);

		if (distanceToPlayer > SeekDistance)
		{
			return m_wander;
		}

		if (auto newPosition = m_transform.getPosition() + glm::normalize(offset) * deltaTime; engine::utility::isWithinBounds(newPosition, m_origin, m_bounds))
		{
			m_transform.setPosition(newPosition);
		}

		if (distanceToPlayer <= BattleDistance)
		{
			m_battleStart->play();

			auto* playerMovement = m_player->getBehavior<MovementController>();

			if (playerMovement->getPower() > m_aiPower)
			{
				m_transform.getScene().removeTransform(m_transform);
				playerMovement->increasePower(1);
			}
			else
			{
				m_transform.getScene().removeTransform(*m_player);
			}
		}

		return this;
	}

	void Flee::exit()
	{
		m_fleeEnd->play();
	}
}
