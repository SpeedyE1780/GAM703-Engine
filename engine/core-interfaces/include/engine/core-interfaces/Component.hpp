#ifndef GAM703_ENGINE_CORE_INTERFACES_ICOMPONENT_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ICOMPONENT_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IEngine.fwd.hpp>
#include <engine/core-interfaces/IScene.fwd.hpp>
#include <engine/core-interfaces/Transform.fwd.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Component
	{
	public:
		Component(Transform* transform);
		virtual ~Component() = default;

		virtual Component* clone(Transform* transform) const = 0;

		Transform* getTransform() { return m_transform; }
		const Transform* getTransform() const { return m_transform; }

		virtual void tick(float deltaTime) = 0;

		IEngine* getEngine();
		const IEngine* getEngine() const;

		IScene* getScene();
		const IScene* getScene() const;

	protected:
		Transform* m_transform;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ICOMPONENT_HPP
