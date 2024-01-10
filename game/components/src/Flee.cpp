#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Flee.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	constexpr float SeekDistance = 3.0f;

	Flee::Flee(engine::components::Transform& transform, engine::components::Transform* player, Wander* wander, engine::components::AudioPlayer* battleStart) : MovementStrategy(transform),
		m_player(player),
		m_wander(wander),
		m_battleStart(battleStart)
	{
		m_fleeStart = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/FleeStart.wav");
		m_fleeEnd = m_transform.addComponent<engine::components::AudioPlayer>("resources/Audio/FleeEnd.wav");
	}

	Flee* Flee::clone(engine::components::Transform& transform) const
	{
		return new Flee(transform, m_player, m_wander, m_battleStart);
	}

	void Flee::enter()
	{
		m_fleeStart->play();
	}

	MovementStrategy* Flee::processMovement(float deltaTime)
	{
		auto offset = m_transform.getPosition() - m_player->getPosition();
		m_transform.translate(glm::normalize(offset) * deltaTime);

		if (glm::length(offset) > SeekDistance)
		{
			exit();
			m_wander->enter();
			return m_wander;
		}

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

		return this;
	}

	void Flee::exit()
	{
		m_fleeEnd->play();
	}
}
