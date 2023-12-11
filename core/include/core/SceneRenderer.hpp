#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <core-interfaces/ISceneRenderer.hpp>
#include <components/Camera.hpp>
#include <components/Renderer.hpp>
#include <glm/mat4x4.hpp>
#include <gui/Window.hpp>

#include <vector>

namespace gam703::engine::core
{
	class SceneRenderer : public core_interface::ISceneRenderer
	{
	public:
		SceneRenderer(gui::Window* window);
		SceneRenderer(gui::Window* window, const std::vector<core_interface::IRenderer*>& sceneObjects);

		virtual void addRenderer(core_interface::IRenderer* sceneObject) override;
		virtual void removeRenderer(core_interface::IRenderer* sceneObject) override;

		void setMainCamera(components::Camera* camera);
		components::Camera* getMainCamera() { return m_mainCamera; }
		const components::Camera* getMainCamera() const { return m_mainCamera; }

		virtual void calculateProjectionMatrix() override;
		virtual void render() const override;

	private:
		std::vector<core_interface::IRenderer*> m_sceneObjects = {};
		components::Camera* m_mainCamera = nullptr;
		glm::mat4 m_projectionMatrix = glm::mat4(1);
		gui::Window* m_window = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
