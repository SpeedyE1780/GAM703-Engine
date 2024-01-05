#ifndef GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IInput.hpp>
#include <engine/core-interfaces/IResourceManager.hpp>
#include <engine/core-interfaces/Scene.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API IEngine
	{
	public:
		IEngine();
		virtual ~IEngine() = default;
		virtual IInput* getInput() = 0;
		virtual const IInput* getInput() const = 0;
		virtual IResourceManager* getResourceManager() = 0;
		virtual const IResourceManager* getResourceManager() const = 0;
		Scene* getScene() { return &m_scene; }
		const Scene* getScene() const {return &m_scene; }
		virtual float getAspectRatio() const = 0;

	protected:
		Scene m_scene;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
