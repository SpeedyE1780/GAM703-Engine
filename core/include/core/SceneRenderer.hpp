#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <components/Camera.hpp>
#include <components/Renderer.hpp>
#include <glm/mat4x4.hpp>
#include <gui/Window.hpp>

#include <vector>

namespace gam703::engine::core
{
	class SceneRenderer
	{
	public:
		SceneRenderer(gui::Window* window);
		SceneRenderer(gui::Window* window, const std::vector<components::Renderer*>& sceneObjects);

		void addRenderer(components::Renderer* sceneObject);
		void removeRenderer(components::Renderer* sceneObject);

		void setMainCamera(components::Camera* camera);
		components::Camera* getMainCamera() { return m_mainCamera; }
		const components::Camera* getMainCamera() const { return m_mainCamera; }

		void calculateProjectionMatrix();
		void render() const;

	private:
		std::vector<components::Renderer*> m_sceneObjects = {};
		components::Camera* m_mainCamera = nullptr;
		glm::mat4 m_projectionMatrix = glm::mat4(1);
		gui::Window* m_window = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
