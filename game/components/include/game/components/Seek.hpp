#ifndef GAM703_GAME_COMPONENTS_SEEK_HPP
#define GAM703_GAME_COMPONENTS_SEEK_HPP

#include <engine/components/AudioPlayer.hpp>

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	class Wander;

	class GAME_COMPONENTS_API Seek : public MovementStrategy
	{
	public:
		Seek(engine::components::Transform& transform, engine::components::Transform* player, Wander* wander, engine::components::AudioPlayer* battleStart);

		virtual Seek* clone(engine::components::Transform& transform) const;

		virtual void enter() override;
		virtual MovementStrategy* processMovement(float deltaTime) override;
		virtual void exit() override;

	private:
		engine::components::Transform* m_player;
		Wander* m_wander = nullptr;
		engine::components::AudioPlayer* m_alert = nullptr;
		engine::components::AudioPlayer* m_deactivate = nullptr;
		engine::components::AudioPlayer* m_battleStart = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_SEEK_HPP
