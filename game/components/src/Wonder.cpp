#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Wonder.hpp>

namespace gam703::game::components
{
	Wonder::Wonder(engine::components::Transform& transform, engine::components::Transform* playerTransform) : engine::components::Behavior(transform), m_origin(transform.getPosition()), m_player(playerTransform)
	{
		m_alert = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Alert.wav");
		m_alert->setAudioMixer(getEngine().getAudioEngine().getAudioMixer("SFX"));
	}

	Wonder* Wonder::clone(engine::components::Transform& transform) const
	{
		return new Wonder(transform, m_player);
	}

	void Wonder::tick(float deltaTime)
	{
		if (glm::distance(m_origin, m_player->getPosition()) > m_radius)
		{
			m_angle += deltaTime;
			m_transform.setPosition(m_origin + glm::vec3(glm::cos(m_angle), 0.0f, glm::sin(m_angle)) * m_radius);
			m_transform.setRotation(0.0f, m_angle, 0.0f);
			m_isChasingPlayer = false;
		}
		else
		{
			if (!m_isChasingPlayer)
			{
				m_isChasingPlayer = true;
				m_alert->play();
			}

			m_transform.setPosition(engine::utility::moveTowards(m_transform.getPosition(), m_player->getPosition(), deltaTime));
		}
	}
}
