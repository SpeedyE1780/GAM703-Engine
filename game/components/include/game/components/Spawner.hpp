#ifndef GAM703_GAME_COMPONENTS_SPAWNER_HPP
#define GAM703_GAME_COMPONENTS_SPAWNER_HPP

#include <engine/components/Component.hpp>

#include <game/components/Config.hpp>
#include <game/components/PowerLevel.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API Spawner : public engine::components::Component
	{
	public:
		Spawner(engine::components::Transform& transform, engine::components::Transform* player, int count, float radius, PowerLevel low, PowerLevel high);

		virtual Spawner* clone(engine::components::Transform& transform) const override;

	private:
		engine::components::Transform* m_player;
		const int m_count;
		const float m_radius;
		const PowerLevel m_lowPowerLevel;
		const PowerLevel m_highPowerLevel;
	};
}


#endif // GAM703_GAME_COMPONENTS_SPAWNER_HPP
