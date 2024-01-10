#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Seek.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	constexpr float SeekDistance = 3.0f;

	Seek::Seek(engine::components::Transform& transform, engine::components::Transform* player, Wander* wander) : MovementStrategy(transform), m_player(player), m_wander(wander)
	{
		m_alert = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Alert.wav");
		m_deactivate = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Deactivate.wav");
		m_battleStart = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/Battle Start.wav");
		auto* sfxMixer = getEngine().getAudioEngine().getAudioMixer("SFX");
		m_alert->setAudioMixer(sfxMixer);
		m_deactivate->setAudioMixer(sfxMixer);
		m_battleStart->setAudioMixer(sfxMixer);
	}

	Seek* Seek::clone(engine::components::Transform& transform) const
	{
		return new Seek(transform, m_player, m_wander);
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
