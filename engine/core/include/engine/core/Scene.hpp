#ifndef GAM703_ENGINE_CORE_Scene_HPP
#define GAM703_ENGINE_CORE_Scene_HPP

#include <engine/components/Transform.hpp>
#include <engine/components/Camera.hpp>

#include <engine/core/Config.hpp>
#include <engine/core/SceneRenderer.hpp>

#include <engine/core/Engine.fwd.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::core
{
	/// @brief Scene contains all the scene objects to be rendered
	class ENGINE_CORE_API Scene
	{
	public:
		/// @brief Create a scene
		/// @param engine The engine running the game
		Scene(Engine& engine);
		~Scene() = default;
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		/// @brief Get the scene renderer
		/// @return The scene renderer
		SceneRenderer& getSceneRenderer() { return m_sceneRenderer; }

		/// @brief Get the scene renderer
		/// @return The scene renderer
		const SceneRenderer& getSceneRenderer() const { return m_sceneRenderer; }

		/// @brief Add a new transform to the scene
		/// @param position Transform position
		/// @param rotation Transform rotation
		/// @param scale Transform scale
		/// @return The newly added transform
		components::Transform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));

		/// @brief Add a new transform to the scene
		/// @param transform The transform to clone to create the newly added transform
		/// @return A clone of the given transform
		components::Transform* addTransform(const components::Transform& transform);

		/// @brief Get the camera currently rendering the scene
		/// @return The camera currently rendering the scene
		components::Camera* getActiveCamera() { return m_sceneRenderer.getActiveCamera(); }

		/// @brief Get the camera currently rendering the scene
		/// @return The camera currently rendering the scene
		const components::Camera* getActiveCamera() const { return m_sceneRenderer.getActiveCamera(); }

		/// @brief Set the camera currently rendering the scene
		/// @param camera The new camera that will be used to render the scene
		void setActiveCamera(components::Camera* camera);

		/// @brief Update all scene objects positions and behaviors then render the scene
		/// @param deltaTime Elapsed time between this frame and the last frame
		void updateScene(float deltaTime);

		/// @brief Update the projection matrix used in the vertex shader after changing the active camera or resizing the window
		void updateSceneProjectionMatrix();

	protected:
		/// @brief The engine running the game
		Engine& m_engine;
		/// @brief The renderer used to render all scene objects
		SceneRenderer m_sceneRenderer{};
		/// @brief All the transform in the scene
		std::vector<std::unique_ptr<components::Transform>> m_transforms{};
	};
}

#endif // GAM703_ENGINE_CORE_Scene_HPP
