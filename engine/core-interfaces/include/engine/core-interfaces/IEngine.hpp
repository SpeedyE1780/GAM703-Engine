#ifndef GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IInput.hpp>
#include <engine/core-interfaces/IResourceManager.hpp>
#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/Time.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API IEngine
	{
	public:
		IEngine(double time, double timeScale = 1.0f);
		virtual ~IEngine() = default;
		virtual IInput* getInput() = 0;
		virtual const IInput* getInput() const = 0;
		Time* getTime() { return &m_time; }
		const Time* getTime() const { return &m_time; }
		virtual IResourceManager* getResourceManager() = 0;
		virtual const IResourceManager* getResourceManager() const = 0;
		virtual IScene* getScene() = 0;
		virtual const IScene* getScene() const = 0;
		virtual float getAspectRatio() const = 0;

	protected:
		Time m_time;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
