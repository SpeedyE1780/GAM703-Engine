#include <engine/core/Time.hpp>

namespace gam703::engine::core
{
	Time::Time(double time, double timeScale) : m_time(time), m_timeScale(timeScale)
	{
	}

	void Time::processTime(double time)
	{
		double previousTime = m_time;
		m_time = time;
		m_deltaTime = m_time - previousTime;
	}

} //gam703::engine::core
