#include <engine/core-interfaces/IEngine.hpp>

namespace gam703::engine::core_interface
{
	IEngine::IEngine(double time, double timeScale) : m_time(time, timeScale), m_scene(this)
	{
	}
}
