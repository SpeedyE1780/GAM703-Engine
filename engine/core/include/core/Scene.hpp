#ifndef GAM703_ENGINE_CORE_SCENE_HPP
#define GAM703_ENGINE_CORE_SCENE_HPP

#include <core/Config.hpp>
#include <core/Engine.fwd.hpp>
#include <core/SceneRenderer.hpp>

#include <core-interfaces/IScene.hpp>

#include <components/Transform.hpp>

#include <vector>

namespace gam703::engine::core
{

	class CORE_API Scene : public core_interface::IScene
	{
	public:
		Scene(Engine* engine);
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		virtual core_interface::ISceneRenderer* getSceneRenderer() override { return &m_sceneRenderer; }
		virtual const core_interface::ISceneRenderer* getSceneRenderer() const override { return &m_sceneRenderer; }

		virtual core_interface::ITransform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) override;
		virtual core_interface::ITransform* addTransform(const core_interface::ITransform* transform) override;

		virtual core_interface::ICamera* getActiveCamera() override { return m_sceneRenderer.getActiveCamera(); }
		virtual const core_interface::ICamera* getActiveCamera() const override { return m_sceneRenderer.getActiveCamera(); }
		virtual void setActiveCamera(core_interface::ICamera* activeCamera) override;

		void updateScene(float deltaTime);

	private:
		Engine* m_engine;
		SceneRenderer m_sceneRenderer;
		std::vector<std::unique_ptr<core_interface::ITransform>> m_transforms{};
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_HPP
