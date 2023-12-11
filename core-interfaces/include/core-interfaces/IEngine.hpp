#ifndef GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP

#include <core-interfaces/ISceneRenderer.hpp>
#include <core-interfaces/IInput.hpp>

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
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IENGINE_HPP
