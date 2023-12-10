#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <components/Renderer.hpp>
#include <vector>

namespace gam703::engine::core
{
	class SceneRenderer
	{
	public:
		SceneRenderer(const std::vector<components::Renderer*>& sceneObjects);

		void render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const;

	private:
		std::vector<components::Renderer*> m_sceneObjects;
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
