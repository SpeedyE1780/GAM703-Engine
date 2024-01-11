#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Flee.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	Flee::Flee(engine::components::Transform& transform, const engine::components::TransformReference& player, Wander* wander) : MovementStrategy(transform),
		m_player(player),
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
		m_transform.translate(glm::normalize(offset) * deltaTime);
		float distanceToPlayer = glm::length(offset);

		if (distanceToPlayer > SeekDistance)
		{
			exit();
			m_wander->enter();
			return m_wander;
		}

		if (distanceToPlayer <= BattleDistance)
		{
			m_battleStart->play();
			float playerNumber = engine::utility::generateRandomNumber(0.0f, 100.0f);
			float backpackNumber = engine::utility::generateRandomNumber(0.0f, 100.0f);

			if (playerNumber > backpackNumber)
			{
				m_transform.getScene().removeTransform(m_transform);
			}
			else
			{
				m_transform.getScene().removeTransform(*m_player.getObject());
			}
		}

		return this;
	}

	void Flee::exit()
	{
		m_fleeEnd->play();
	}
}
