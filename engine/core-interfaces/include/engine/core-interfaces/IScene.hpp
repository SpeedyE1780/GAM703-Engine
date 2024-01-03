#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP

#include <engine/core-interfaces/Transform.fwd.hpp>
#include <engine/core-interfaces/ISceneRenderer.hpp>
#include <engine/core-interfaces/Camera.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class IScene
	{
	public:
		virtual ~IScene() = default;

		virtual ISceneRenderer* getSceneRenderer() = 0;
		virtual const ISceneRenderer* getSceneRenderer() const = 0;

		virtual Transform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) = 0;
		virtual Transform* addTransform(const Transform* transform) = 0;

		virtual Camera* getActiveCamera() = 0;
		virtual const Camera* getActiveCamera() const = 0;
		virtual void setActiveCamera(Camera* camera) = 0;

		virtual void updateSceneProjectionMatrix() = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
