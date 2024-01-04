#ifndef GAM703_GAME_COMPONENTS_WONDER_HPP
#define GAM703_GAME_COMPONENTS_WONDER_HPP

#include <engine/core-interfaces/Component.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API Wonder : public engine::core_interface::Component
	{
	public:
		Wonder(engine::core_interface::Transform* transform, engine::core_interface::Transform* playerTransform);

		virtual engine::core_interface::Component* clone(engine::core_interface::Transform* transform) const override;
		virtual void tick(float deltaTime) override;

	private:
		glm::vec3 m_origin;
		float m_radius = 4.5f;
		float m_angle = 0.0f;
		engine::core_interface::Transform* m_player = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_WONDER_HPP
