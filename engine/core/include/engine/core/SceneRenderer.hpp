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

		virtual void render() const override;
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
