#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <engine/core-interfaces/ISceneRenderer.hpp>
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

		virtual void calculateProjectionMatrix(float aspectRatio) override;
		virtual void render() const override;

		virtual void setDirectionalLight(core_interface::ILight* light) override;
		virtual core_interface::ILight* getDirectionalLight() override { return m_directionalLight; }
		virtual const core_interface::ILight* getDirectionalLight() const override { return m_directionalLight; }

		virtual void addLightSource(core_interface::ILight* light) override;
		virtual void removeLightSource(core_interface::ILight* light) override;

	private:
		std::vector<core_interface::IRenderer*> m_sceneObjects{};
		components::DirectionalLight* m_directionalLight = nullptr;
		std::vector<core_interface::ILight*> m_lightSources{};
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
