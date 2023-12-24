#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <engine/core-interfaces/ISceneRenderer.hpp>
#include <engine/core-interfaces/ICamera.hpp>
#include <engine/core-interfaces/IRenderer.hpp>

#include <glm/mat4x4.hpp>

#include <vector>

namespace gam703::engine::core
{
	class SceneRenderer : public core_interface::ISceneRenderer
	{
	public:
		SceneRenderer() = default;
		SceneRenderer(const std::vector<core_interface::IRenderer*>& sceneObjects);

		virtual void addRenderer(core_interface::IRenderer* sceneObject) override;
		virtual void removeRenderer(core_interface::IRenderer* sceneObject) override;

		void setActiveCamera(core_interface::ICamera* camera) { m_activeCamera = camera; }
		core_interface::ICamera* getActiveCamera() { return m_activeCamera; }
		const core_interface::ICamera* getActiveCamera() const { return m_activeCamera; }

		virtual void setAmbientLight(const glm::vec3& ambientLight) override;
		virtual const glm::vec3& getAmbientLight() const override { return m_ambientLightColor; }

		virtual void calculateProjectionMatrix(float aspectRatio) override;
		virtual void render() const override;

	private:
		std::vector<core_interface::IRenderer*> m_sceneObjects = {};
		core_interface::ICamera* m_activeCamera = nullptr;
		glm::mat4 m_projectionMatrix = glm::mat4(1);
		glm::vec3 m_ambientLightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
