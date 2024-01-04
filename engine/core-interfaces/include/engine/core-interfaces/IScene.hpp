#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP

#include <engine/core-interfaces/Transform.fwd.hpp>
#include <engine/core-interfaces/SceneRenderer.hpp>
#include <engine/core-interfaces/Camera.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class IScene
	{
	public:
		virtual ~IScene() = default;

		SceneRenderer* getSceneRenderer() { return &m_sceneRenderer; }
		const SceneRenderer* getSceneRenderer() const { return &m_sceneRenderer; }

		virtual Transform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) = 0;
		virtual Transform* addTransform(const Transform* transform) = 0;

		Camera* getActiveCamera() { return m_sceneRenderer.getActiveCamera(); }
		const Camera* getActiveCamera() const { return m_sceneRenderer.getActiveCamera(); }
		virtual void setActiveCamera(Camera* camera) = 0;

		virtual void updateSceneProjectionMatrix() = 0;

	protected:
		SceneRenderer m_sceneRenderer{};
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
