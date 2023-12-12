#ifndef GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP

#include <core-interfaces/IInput.hpp>
#include <core-interfaces/IResourceManager.hpp>
#include <core-interfaces/IScene.hpp>
#include <core-interfaces/ISceneRenderer.hpp>
#include <core-interfaces/ITime.hpp>

namespace gam703::engine::core_interface
{
	class IEngine
	{
	public:
		virtual ~IEngine() = default;
		virtual IInput* getInput() = 0;
		virtual const IInput* getInput() const = 0;
		virtual ISceneRenderer* getSceneRenderer() = 0;
		virtual const ISceneRenderer* getSceneRenderer() const = 0;
		virtual ITime* getTime() = 0;
		virtual const ITime* getTime() const = 0;
		virtual IResourceManager* getResourceManager() = 0;
		virtual const IResourceManager* getResourceManager() const = 0;
		virtual IScene* getScene() = 0;
		virtual const IScene* getScene() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
