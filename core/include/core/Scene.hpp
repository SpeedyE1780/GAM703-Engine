#ifndef GAM703_ENGINE_CORE_SCENE_HPP
#define GAM703_ENGINE_CORE_SCENE_HPP

#include <core-interfaces/IScene.hpp>

#include <components/Transform.hpp>

#include <vector>

namespace gam703::engine::core
{
	class Engine;

	class Scene : public core_interface::IScene
	{
	public:
		Scene(Engine* engine);

		virtual core_interface::ITransform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) override;
		virtual core_interface::ITransform* addTransform(const core_interface::ITransform* transform) override;

		void updateScene() const;

	private:
		Engine* m_engine;
		std::vector<std::unique_ptr<core_interface::ITransform>> m_transforms{};
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_HPP
