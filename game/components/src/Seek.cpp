#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Seek.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	Seek::Seek(engine::components::Transform& transform, engine::components::Transform* player, Wander* wander) : MovementStrategy(transform),
		m_player(player),
		m_wander(wander)
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
		m_transform.setPosition(engine::utility::moveTowards(m_transform.getPosition(), m_player->getPosition(), deltaTime));

		float distanceToPlayer = glm::length(m_transform.getPosition() - m_player->getPosition());

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
				m_transform.getScene().removeTransform(*m_player);
			}
		}

		if (distanceToPlayer > SeekDistance)
		{
			exit();
			m_wander->enter();
			return m_wander;
		}

		return this;
	}

	void Seek::exit()
	{
		m_deactivate->play();
	}
}
