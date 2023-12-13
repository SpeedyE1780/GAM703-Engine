#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP

#include <engine/core-interfaces/ITransform.fwd.hpp>
#include <engine/core-interfaces/ISceneRenderer.hpp>
#include <engine/core-interfaces/ICamera.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class IScene
	{
	public:
		virtual ~IScene() = default;

		virtual ISceneRenderer* getSceneRenderer() = 0;
		virtual const ISceneRenderer* getSceneRenderer() const = 0;

		virtual ITransform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) = 0;
		virtual ITransform* addTransform(const ITransform* transform) = 0;

		virtual ICamera* getActiveCamera() = 0;
		virtual const ICamera* getActiveCamera() const = 0;
		virtual void setActiveCamera(ICamera* camera) = 0;

		virtual void updateSceneProjectionMatrix() = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
