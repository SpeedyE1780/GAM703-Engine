#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Seek.hpp>
#include <game/components/MovementController.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	Seek::Seek(engine::components::Transform& transform, const engine::components::TransformReference& player, Wander* wander, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower) : MovementStrategy(transform),
		m_player(player),
		m_wander(wander),
		m_origin(origin),
		m_bounds(bounds),
		m_aiPower(aiPower)
	{
		m_alert = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Alert.wav");
		m_deactivate = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Deactivate.wav");
		auto* sfxMixer = m_transform.getEngine().getAudioEngine().getAudioMixer("SFX");
		m_alert->setAudioMixer(sfxMixer);
		m_deactivate->setAudioMixer(sfxMixer);
	}

	void Seek::enter()
	{
		m_alert->play();
	}

	MovementStrategy* Seek::processMovement(float deltaTime)
	{
		if (!m_player)
		{
			return m_wander;
		}

		float distanceToPlayer = glm::length(m_transform.getPosition() - m_player->getPosition());
		auto* playerMovement = m_player->getBehavior<MovementController>();

		if (auto newPosition = engine::utility::moveTowards(m_transform.getPosition(), m_player->getPosition(), deltaTime); engine::utility::isWithinBounds(newPosition, m_origin, m_bounds))
		{
			m_transform.setPosition(newPosition);
		}

		if (distanceToPlayer <= BattleDistance)
		{
			m_battleStart->play();

			if (playerMovement->getPower() > m_aiPower)
			{
				m_transform.getScene().removeTransform(m_transform);
				playerMovement->increasePower(m_aiPower);
			}
			else
			{
				m_transform.getScene().removeTransform(*m_player);
			}
		}

		if (distanceToPlayer > SeekDistance || playerMovement->getPower() > m_aiPower)
		{
			return m_wander;
		}

		return this;
	}

	void Seek::exit()
	{
		m_deactivate->play();
	}
}
