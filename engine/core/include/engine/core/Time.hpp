#ifndef GAM703_ENGINE_CORE_TIME_HPP
#define GAM703_ENGINE_CORE_TIME_HPP

#include <engine/core/Config.hpp>

namespace gam703::engine::core
{
	/// @brief Time processes the engine time step
	class ENGINE_CORE_API Time
	{
	public:
		/// @brief Create Time processor
		/// @param time Current glfw time
		/// @param timeScale Time multiplier  to slow/speed up time
		Time(double time, double timeScale = 1);
		~Time() = default;

		/// @brief Update delta time and current time
		/// @param time The current glfw time
		void processTime(double time);

		/// @brief Get time since engine started
		/// @return Time since engine started
		double getTime() const { return m_time; }

		/// @brief Get elapsed time between this frame and the last frame multiplied by the timeScale
		/// @return Elapsed time between this frame and the last frame multiplied by the timeScale
		double getDeltaTime() const { return m_deltaTime * m_timeScale; }

		/// @brief Get elapsed time between this frame and the last frame
		/// @return Elapsed time between this frame and the last frame
		double getUnscaledDeltaTime() const { return m_deltaTime; }

		/// @brief Get the time scale factor
		/// @return The factor by which time is slow/sped up
		double getTimeScale() const { return m_timeScale; }

		/// @brief Set the time scale factor
		/// @param timeScale The factor by which time is slow/sped up
		void setTimeScale(double timeScale) { m_timeScale = timeScale; }

	private:
		/// @brief Time since engine started
		double m_time = 0;
		/// @brief The factor by which time is slow/sped up
		double m_timeScale = 1;
		/// @brief Elapsed time between this frame and the last frame
		double m_deltaTime = 0;
	};
}

#endif // GAM703_ENGINE_CORE_TIME_HPP
