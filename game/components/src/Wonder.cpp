#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Wonder.hpp>

namespace gam703::game::components
{
	Wonder::Wonder(engine::components::Transform& transform, engine::components::Transform* playerTransform, const glm::vec3& origin, float radius) : engine::components::Behavior(transform), m_origin(origin), m_player(playerTransform), m_radius(radius)
	{
		m_alert = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Alert.wav");
		m_deactivate = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Deactivate.wav");
		m_battleStart = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Battle Start.wav");
		auto* sfxMixer = getEngine().getAudioEngine().getAudioMixer("SFX");
		m_alert->setAudioMixer(sfxMixer);
		m_deactivate->setAudioMixer(sfxMixer);
		m_battleStart->setAudioMixer(sfxMixer);
	}

	Wonder* Wonder::clone(engine::components::Transform& transform) const
	{
		return new Wonder(transform, m_player, m_origin, m_radius);
	}

	void Wonder::tick(float deltaTime)
	{
		float distanceToPlayer = glm::distance(m_transform.getPosition(), m_player->getPosition());

		if (distanceToPlayer > m_radius)
		{
			if (m_isChasingPlayer)
			{
				m_deactivate->play();
				m_isChasingPlayer = false;
			}

			m_angle += deltaTime;
			m_transform.setPosition(m_origin + glm::vec3(glm::cos(m_angle), 0.0f, glm::sin(m_angle)) * m_radius);
			m_transform.setRotation(0.0f, m_angle, 0.0f);
		}
		else
		{
			if (!m_isChasingPlayer)
			{
				m_isChasingPlayer = true;
				m_alert->play();
			}

			m_transform.setPosition(engine::utility::moveTowards(m_transform.getPosition(), m_player->getPosition(), deltaTime));
			float distanceToPlayer = glm::distance(m_transform.getPosition(), m_player->getPosition());

			if (distanceToPlayer - deltaTime < 0.2f)
			{
				m_battleStart->play();

				float playerNumber = engine::utility::generateRandomNumber(0.0f, 100.0f);
				float backpackNumber = engine::utility::generateRandomNumber(0.0f, 100.0f);

				if (playerNumber > backpackNumber || true)
				{
					getScene().removeTransform(m_transform);
				}
				else
				{
					getScene().removeTransform(*m_player);
					getEngine().getTime().setTimeScale(0.0f);
				}
			}
		}
	}
}
