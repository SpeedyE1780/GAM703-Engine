#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Camera.hpp>
#include <engine/core-interfaces/IRenderer.hpp>
#include <engine/core-interfaces/ILight.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API ISceneRenderer
	{
	public:
		virtual ~ISceneRenderer() = default;
		virtual void addRenderer(IRenderer* renderer) = 0;
		virtual void removeRenderer(IRenderer* sceneObject) = 0;

		virtual void calculateProjectionMatrix(float aspectRatio);
		virtual void render() const = 0;

		void setAmbientLight(const glm::vec3& color, float strength);
		void setAmbientLightColor(const glm::vec3& color);
		const glm::vec3& getAmbientLightColor() const { return m_ambientLight.m_color; }
		void setAmbientLightIntensity(float intensity);
		float getAmbientLightIntensity() const { return m_ambientLight.m_intensity; }

		virtual void setDirectionalLight(ILight* light) = 0;
		virtual ILight* getDirectionalLight() = 0;
		virtual const ILight* getDirectionalLight() const = 0;

		virtual void addLightSource(ILight* light) = 0;
		virtual void removeLightSource(ILight* light) = 0;

		void setActiveCamera(Camera* camera) { m_activeCamera = camera; }
		Camera* getActiveCamera() { return m_activeCamera; }
		const Camera* getActiveCamera() const { return m_activeCamera; }

	protected:
		struct AmbientLight
		{
			glm::vec3 m_color = glm::vec3(1.0f, 1.0f, 1.0f);
			float m_intensity = 0.1f;
		};

		Camera* m_activeCamera = nullptr;
		mutable bool m_shouldUpdateAmbientLight = false;
		AmbientLight m_ambientLight{};
		glm::mat4 m_projectionMatrix = glm::mat4(1);
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
