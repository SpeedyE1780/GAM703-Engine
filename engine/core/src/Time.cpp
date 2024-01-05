#include <engine/core/Time.hpp>

namespace gam703::engine::core
{
	Time::Time(double time, double timeScale) : m_time(time), m_timeScale(timeScale)
	{
	}

	void Time::processTime(double time)
	{
		m_deltaTime = time - m_time;
		m_time = time;
	}
}
