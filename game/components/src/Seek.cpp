#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Seek.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	constexpr float SeekDistance = 3.0f;

	Seek::Seek(engine::components::Transform& transform, engine::components::Transform* player, Wander* wander, engine::components::AudioPlayer* battleStart) : MovementStrategy(transform),
		m_player(player),
		m_wander(wander),
		m_battleStart(battleStart)
	{
		m_alert = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Alert.wav");
		m_deactivate = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Deactivate.wav");
		auto* sfxMixer = getEngine().getAudioEngine().getAudioMixer("SFX");
		m_alert->setAudioMixer(sfxMixer);
		m_deactivate->setAudioMixer(sfxMixer);
	}

	Seek* Seek::clone(engine::components::Transform& transform) const
	{
		return new Seek(transform, m_player, m_wander, m_battleStart);
	}

	void Seek::enter()
	{
		m_alert->play();
	}

	MovementStrategy* Seek::processMovement(float deltaTime)
	{
		m_transform.setPosition(engine::utility::moveTowards(m_transform.getPosition(), m_player->getPosition(), deltaTime));

		if (m_transform.getPosition() == m_player->getPosition())
		{
			m_battleStart->play();
			float playerNumber = engine::utility::generateRandomNumber(0.0f, 100.0f);
			float backpackNumber = engine::utility::generateRandomNumber(0.0f, 100.0f);

			if (playerNumber > backpackNumber)
			{
				getScene().removeTransform(m_transform);
			}
			else
			{
				getScene().removeTransform(*m_player);
				getEngine().getTime().setTimeScale(0.0f);
			}
		}

		if (glm::length(m_transform.getPosition() - m_player->getPosition()) > SeekDistance)
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
