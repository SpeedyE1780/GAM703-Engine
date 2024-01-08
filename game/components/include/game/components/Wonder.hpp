#ifndef GAM703_GAME_COMPONENTS_WONDER_HPP
#define GAM703_GAME_COMPONENTS_WONDER_HPP

#include <engine/components/AudioPlayer.hpp>
#include <engine/components/Behavior.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API Wonder : public engine::components::Behavior
	{
	public:
		Wonder(engine::components::Transform& transform, engine::components::Transform* playerTransform, const glm::vec3& origin, float radius = 4.5f);

		virtual Wonder* clone(engine::components::Transform& transform) const override;
		virtual void tick(float deltaTime) override;

	private:
		glm::vec3 m_origin;
		float m_radius = 4.5f;
		float m_angle = 0.0f;
		bool m_isChasingPlayer = false;
		engine::components::Transform* m_player = nullptr;
		engine::components::AudioPlayer* m_alert = nullptr;
		engine::components::AudioPlayer* m_deactivate = nullptr;
		engine::components::AudioPlayer* m_battleStart = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_WONDER_HPP
