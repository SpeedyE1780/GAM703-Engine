#ifndef GAM703_ENGINE_CORE_INTERFACES_ICOMPONENT_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ICOMPONENT_HPP

#include <core-interfaces/Config.hpp>
#include <core-interfaces/ITransform.fwd.hpp>
#include <core-interfaces/IEngine.hpp>

namespace gam703::engine::core_interface
{
	class CORE_INTERFACES_API IComponent
	{
	public:
		IComponent(ITransform* transform);
		virtual ~IComponent() = default;

		virtual IComponent* clone(ITransform* transform) const = 0;

		ITransform* getTransform() { return m_transform; }
		const ITransform* getTransform() const { return m_transform; }

		virtual void tick(float deltaTime) = 0;

		core_interface::IEngine* getEngine();
		const core_interface::IEngine* getEngine() const;

	protected:
		ITransform* m_transform;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ICOMPONENT_HPP
