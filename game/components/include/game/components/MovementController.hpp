#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP

#include <engine/components/AudioPlayer.hpp>
#include <engine/components/Behavior.hpp>
#include <engine/components/Renderer.hpp>

#include <game/components/Config.hpp>
#include <game/components/PowerLevel.hpp>

namespace gam703::game::components
{
	/// @brief MovementController allows moving a transform with a keyboard
	class GAME_COMPONENTS_API MovementController : public engine::components::Behavior
	{
	public:
		/// @brief Create a behavior to move the transform with the keyboard
		/// @param transform The transform owning this behavior
		MovementController(engine::components::Transform& transform);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned MovementController belonging to the transform
		virtual MovementController* clone(engine::components::Transform& transform) const override;

		/// @brief Check for keyboard input and move transform
		/// @param deltaTime Elapsed time between this frame and the last frame
		virtual void tick(float deltaTime) override;

		/// @brief Increase player power level
		/// @param power the added power to give
		void increasePower(int power);

		/// @brief Get the player power level
		/// @return The player power level
		int getPower() const {return m_power;}

	private:
		/// @brief Check for input and move player
		void updatePosition();

		/// @brief Bell to play when pressing space
		engine::components::AudioPlayer* m_bell;
		/// @brief The renderer component
		engine::components::Renderer* m_renderer;
		/// @brief The player movement speed
		float m_movementSpeed = 2.5f;
		/// @brief The player power level
		int m_power = static_cast<int>(PowerLevel::Weaker);
		/// @brief Checks if time is currently slowed down
		bool m_slowDownActive = false;
		/// @brief The duration of the slow down power up
		float m_slowDownDuration = 0.0f;
		/// @brief The cooldown until the slow down power up can be activated again
		float m_slowDownCooldown = 0.0f;
		/// @brief Little cube that'll show up once the power up can be activated
		engine::components::TransformReference m_powerIndicator{ nullptr };
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
