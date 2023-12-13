#ifndef GAM703_ENGINE_CORE_INTERFACES_ITIME_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ITIME_HPP

namespace gam703::engine::core_interface
{
	class ITime
	{
	public:
		~ITime() = default;

		virtual void processTime(double time) = 0;

		virtual double getTime() const = 0;
		virtual double getDeltaTime() const = 0;
		virtual double getUnscaledDeltaTime() const = 0;
		virtual double getTimeScale() const = 0;

		virtual void setTimeScale(double timeScale) = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ITIME_HPP
