#ifndef GAM703_ENGINE_CORE_TIME_HPP
#define GAM703_ENGINE_CORE_TIME_HPP

#include <core/Config.hpp>
#include <core-interfaces/ITime.hpp>

namespace gam703::engine::core
{
	class CORE_API Time : public core_interface::ITime
	{
	public:
		Time(double time, double timeScale = 1);

		virtual void processTime(double time) override;

		virtual double getTime() const override { return m_time; }
		virtual double getDeltaTime() const override { return m_deltaTime * m_timeScale; }
		virtual double getUnscaledDeltaTime() const override { return m_deltaTime; }
		virtual double getTimeScale() const override { return m_timeScale; }

		virtual void setTimeScale(double timeScale) override { m_timeScale = timeScale; }

	private:
		double m_time = 0;
		double m_timeScale = 1;
		double m_deltaTime = 0;
	};
}

#endif // GAM703_ENGINE_CORE_TIME_HPP
