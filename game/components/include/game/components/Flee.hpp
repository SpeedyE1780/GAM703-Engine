#ifndef GAM703_GAME_COMPONENTS_FLEE_HPP
#define GAM703_GAME_COMPONENTS_FLEE_HPP

#include <engine/components/AudioPlayer.hpp>

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	class Wander;

	class GAME_COMPONENTS_API Flee : public MovementStrategy
	{
	public:
		Flee(engine::components::Transform& transform, engine::components::Transform* player, Wander* wander, engine::components::AudioPlayer* battleStart);

		virtual Flee* clone(engine::components::Transform& transform) const override;

		virtual void enter() override;
		virtual MovementStrategy* processMovement(float deltaTime) override;
		virtual void exit() override;

	private:
		engine::components::Transform* m_player;
		Wander* m_wander;
		engine::components::AudioPlayer* m_fleeStart = nullptr;
		engine::components::AudioPlayer* m_fleeEnd = nullptr;
		engine::components::AudioPlayer* m_battleStart = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_FLEE_HPP
