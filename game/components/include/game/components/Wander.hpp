#ifndef GAM703_GAME_COMPONENTS_WANDER_HPP
#define GAM703_GAME_COMPONENTS_WANDER_HPP

#include <engine/components/AudioPlayer.hpp>

#include <game/components/Flee.hpp>
#include <game/components/MovementStrategy.hpp>
#include <game/components/Seek.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>


namespace gam703::game::components
{
	class GAME_COMPONENTS_API Wander : public MovementStrategy
	{
	public:
		Wander(engine::components::Transform& transform, const engine::components::TransformReference& playerTransform, const glm::vec3& origin, const glm::vec2& bounds);

		void setSeek(Seek* seek) { m_seek = seek; }
		void setFlee(Flee* flee) { m_flee = flee; }

		virtual void enter() override;
		virtual MovementStrategy* processMovement(float deltaTime) override;
		virtual void exit() override;

	private:
		glm::vec3 m_origin;
		glm::vec2 m_bounds;
		glm::vec3 m_currentTarget;
		engine::components::TransformReference m_player;
		Seek* m_seek = nullptr;
		Flee* m_flee = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_WANDER_HPP
