#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <engine/core-interfaces/ISceneRenderer.hpp>
#include <engine/core-interfaces/ICamera.hpp>
#include <engine/core-interfaces/IRenderer.hpp>

#include <engine/components/DirectionalLight.hpp>

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

		virtual void setAmbientLight(const glm::vec3& color, float strength) override;
		virtual void setAmbientLightColor(const glm::vec3& color) override;
		virtual const glm::vec3& getAmbientLightColor() const override { return m_ambientLight.m_color; }
		virtual void setAmbientLightIntensity(float intensity) override;
		virtual float getAmbientLightIntensity() const { return m_ambientLight.m_intensity; }

		virtual void calculateProjectionMatrix(float aspectRatio) override;
		virtual void render() const override;

		virtual void setDirectionalLight(core_interface::ILight* light) override;
		virtual core_interface::ILight* getDirectionalLight() override { return m_directionalLight; }
		virtual const core_interface::ILight* getDirectionalLight() const override { return m_directionalLight; }

	private:
		struct AmbientLight
		{
			glm::vec3 m_color = glm::vec3(1.0f, 1.0f, 1.0f);
			float m_intensity = 0.1f;
		};

		std::vector<core_interface::IRenderer*> m_sceneObjects = {};
		core_interface::ICamera* m_activeCamera = nullptr;
		glm::mat4 m_projectionMatrix = glm::mat4(1);
		AmbientLight m_ambientLight{};
		components::DirectionalLight* m_directionalLight = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
