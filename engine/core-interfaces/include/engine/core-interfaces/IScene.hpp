#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IEngine.fwd.hpp>
#include <engine/core-interfaces/Transform.hpp>
#include <engine/core-interfaces/SceneRenderer.hpp>
#include <engine/core-interfaces/Camera.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API IScene
	{
	public:
		IScene(IEngine* engine);
		virtual ~IScene() = default;
		IScene(const IScene&) = delete;
		IScene& operator=(const IScene&) = delete;

		SceneRenderer* getSceneRenderer() { return &m_sceneRenderer; }
		const SceneRenderer* getSceneRenderer() const { return &m_sceneRenderer; }

		Transform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));
		Transform* addTransform(const Transform* transform);

		Camera* getActiveCamera() { return m_sceneRenderer.getActiveCamera(); }
		const Camera* getActiveCamera() const { return m_sceneRenderer.getActiveCamera(); }
		void setActiveCamera(Camera* camera);

		void updateScene(float deltaTime);

		void updateSceneProjectionMatrix();

	protected:
		IEngine* m_engine;
		SceneRenderer m_sceneRenderer{};
		std::vector<std::unique_ptr<Transform>> m_transforms{};
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
