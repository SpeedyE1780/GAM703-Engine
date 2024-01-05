#ifndef GAM703_ENGINE_CORE_INTERFACES_Scene_HPP
#define GAM703_ENGINE_CORE_INTERFACES_Scene_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IEngine.fwd.hpp>
#include <engine/components/Transform.hpp>
#include <engine/core-interfaces/SceneRenderer.hpp>
#include <engine/components/Camera.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Scene
	{
	public:
		Scene(IEngine* engine);
		virtual ~Scene() = default;
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		SceneRenderer* getSceneRenderer() { return &m_sceneRenderer; }
		const SceneRenderer* getSceneRenderer() const { return &m_sceneRenderer; }

		components::Transform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));
		components::Transform* addTransform(const components::Transform* transform);

		components::Camera* getActiveCamera() { return m_sceneRenderer.getActiveCamera(); }
		const components::Camera* getActiveCamera() const { return m_sceneRenderer.getActiveCamera(); }
		void setActiveCamera(components::Camera* camera);

		void updateScene(float deltaTime);

		void updateSceneProjectionMatrix();

	protected:
		IEngine* m_engine;
		SceneRenderer m_sceneRenderer{};
		std::vector<std::unique_ptr<components::Transform>> m_transforms{};
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_Scene_HPP
