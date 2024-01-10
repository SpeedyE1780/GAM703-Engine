#ifndef GAM703_GAME_COMPONENTS_WANDER_HPP
#define GAM703_GAME_COMPONENTS_WANDER_HPP

#include <engine/components/AudioPlayer.hpp>

#include <game/components/MovementStrategy.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>


namespace gam703::game::components
{
	class Seek;

	class GAME_COMPONENTS_API Wander : public MovementStrategy
	{
	public:
		Wander(engine::components::Transform& transform, engine::components::Transform* playerTransform, const glm::vec3& origin, const glm::vec2& bounds);

		virtual Wander* clone(engine::components::Transform& transform) const override;

		virtual void enter() override;
		virtual MovementStrategy* processMovement(float deltaTime) override;
		virtual void exit() override;

	private:
		glm::vec3 m_origin;
		glm::vec2 m_bounds;
		glm::vec3 m_currentTarget;
		engine::components::Transform* m_player = nullptr;
		Seek* m_seek = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_WANDER_HPP
