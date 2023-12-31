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
		virtual ~IEngine() = default;
		virtual IInput* getInput() = 0;
		virtual const IInput* getInput() const = 0;
		virtual Time* getTime() = 0;
		virtual const Time* getTime() const = 0;
		virtual IResourceManager* getResourceManager() = 0;
		virtual const IResourceManager* getResourceManager() const = 0;
		virtual IScene* getScene() = 0;
		virtual const IScene* getScene() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
