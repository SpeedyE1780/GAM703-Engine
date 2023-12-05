#ifndef GAM703_ENGINE_CORE_TIME_HPP
#define GAM703_ENGINE_CORE_TIME_HPP

namespace gam703::engine::core
{
	class Time
	{
	public:
		Time(double time);

		double getTime() const { return m_time; }

	private:
		double m_time = 0;
		double m_deltaTime = 0;
		double m_timeScale = 1;
	};
}

#endif // GAM703_ENGINE_CORE_TIME_HPP
