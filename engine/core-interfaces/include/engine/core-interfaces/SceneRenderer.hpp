#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Camera.hpp>
#include <engine/core-interfaces/IRenderer.hpp>
#include <engine/core-interfaces/Light.hpp>

#include <glm/glm.hpp>

#include <vector>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API SceneRenderer
	{
	public:
		void addRenderer(IRenderer* renderer);
		void removeRenderer(IRenderer* sceneObject);

		void calculateProjectionMatrix(float aspectRatio);
		void render() const;

		void setAmbientLight(const glm::vec3& color, float strength);
		void setAmbientLightColor(const glm::vec3& color);
		const glm::vec3& getAmbientLightColor() const { return m_ambientLight.m_color; }
		void setAmbientLightIntensity(float intensity);
		float getAmbientLightIntensity() const { return m_ambientLight.m_intensity; }

		void addLightSource(Light* light);
		void removeLightSource(Light* light);

		void setActiveCamera(Camera* camera) { m_activeCamera = camera; }
		Camera* getActiveCamera() { return m_activeCamera; }
		const Camera* getActiveCamera() const { return m_activeCamera; }

	private:
		struct AmbientLight
		{
			glm::vec3 m_color = glm::vec3(1.0f, 1.0f, 1.0f);
			float m_intensity = 0.1f;
		};

		Camera* m_activeCamera = nullptr;
		mutable bool m_shouldUpdateAmbientLight = false;
		AmbientLight m_ambientLight{};
		glm::mat4 m_projectionMatrix = glm::mat4(1);
		std::vector<core_interface::IRenderer*> m_sceneObjects{};
		std::vector<core_interface::Light*> m_lightSources{};
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
