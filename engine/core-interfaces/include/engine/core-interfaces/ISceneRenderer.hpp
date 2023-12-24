#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP

#include <engine/core-interfaces/IRenderer.hpp>

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

		virtual void setAmbientLight(const glm::vec3& ambientLight) = 0;
		virtual const glm::vec3& getAmbientLight() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_RENDERER_HPP
