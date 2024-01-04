#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <engine/core-interfaces/ISceneRenderer.hpp>
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

		virtual void calculateProjectionMatrix(float aspectRatio) override;
		virtual void render() const override;

	private:
		std::vector<core_interface::IRenderer*> m_sceneObjects{};
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
