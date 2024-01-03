#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP

#include <engine/core-interfaces/Camera.hpp>
#include <engine/core-interfaces/IRenderer.hpp>
#include <engine/core-interfaces/ILight.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class ISceneRenderer
	{
	public:
		virtual ~ISceneRenderer() = default;
		virtual void addRenderer(IRenderer* renderer) = 0;
		virtual void removeRenderer(IRenderer* sceneObject) = 0;

		virtual void calculateProjectionMatrix(float aspectRatio) = 0;
		virtual void render() const = 0;

		virtual void setAmbientLight(const glm::vec3& color, float strength) = 0;
		virtual void setAmbientLightColor(const glm::vec3& color) = 0;
		virtual const glm::vec3& getAmbientLightColor() const = 0;
		virtual void setAmbientLightIntensity(float intensity) = 0;
		virtual float getAmbientLightIntensity() const = 0;
		virtual void setDirectionalLight(ILight* light) = 0;
		virtual ILight* getDirectionalLight() = 0;
		virtual const ILight* getDirectionalLight() const = 0;

		virtual void addLightSource(ILight* light) = 0;
		virtual void removeLightSource(ILight* light) = 0;

		void setActiveCamera(Camera* camera) { m_activeCamera = camera; }
		Camera* getActiveCamera() { return m_activeCamera; }
		const Camera* getActiveCamera() const { return m_activeCamera; }

	protected:
		Camera* m_activeCamera = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
