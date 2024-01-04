#ifndef GAM703_ENGINE_CORE_SCENE_HPP
#define GAM703_ENGINE_CORE_SCENE_HPP

#include <engine/core/Config.hpp>
#include <engine/core/Engine.fwd.hpp>

#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/Transform.hpp>

#include <vector>

namespace gam703::engine::core
{

	class ENGINE_CORE_API Scene : public core_interface::IScene
	{
	public:
		Scene(Engine* engine);
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		virtual core_interface::Transform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) override;
		virtual core_interface::Transform* addTransform(const core_interface::Transform* transform) override;

		virtual void setActiveCamera(core_interface::Camera* activeCamera) override;

		void updateScene(float deltaTime);
		virtual void updateSceneProjectionMatrix() override;

	private:
		Engine* m_engine;
		std::vector<std::unique_ptr<core_interface::Transform>> m_transforms{};
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_HPP
