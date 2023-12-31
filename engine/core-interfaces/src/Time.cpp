#include <engine/core-interfaces/Time.hpp>

namespace gam703::engine::core_interface
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
