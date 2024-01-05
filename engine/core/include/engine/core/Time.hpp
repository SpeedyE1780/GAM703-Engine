#ifndef GAM703_ENGINE_CORE_TIME_HPP
#define GAM703_ENGINE_CORE_TIME_HPP

#include <engine/core/Config.hpp>

namespace gam703::engine::core
{
	class ENGINE_CORE_API Time
	{
	public:
		Time(double time, double timeScale = 1);
		~Time() = default;

		void processTime(double time);

		double getTime() const { return m_time; }
		double getDeltaTime() const { return m_deltaTime * m_timeScale; }
		double getUnscaledDeltaTime() const { return m_deltaTime; }
		double getTimeScale() const { return m_timeScale; }

		void setTimeScale(double timeScale) { m_timeScale = timeScale; }

	private:
		double m_time = 0;
		double m_timeScale = 1;
		double m_deltaTime = 0;
	};
}

#endif // GAM703_ENGINE_CORE_TIME_HPP
