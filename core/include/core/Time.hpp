#ifndef GAM703_ENGINE_CORE_TIME_HPP
#define GAM703_ENGINE_CORE_TIME_HPP

namespace gam703::engine::core
{
	class Time
	{
	public:
		Time(double time, double timeScale = 1);

		void processTime(double time);

		double getTime() const { return m_time; }
		double getDeltaTime() const { return m_deltaTime; }
		double getTimeScale() const { return m_timeScale; }

	private:
		double m_time = 0;
		double m_timeScale = 1;
		double m_deltaTime = 0;
	};
}

#endif // GAM703_ENGINE_CORE_TIME_HPP
