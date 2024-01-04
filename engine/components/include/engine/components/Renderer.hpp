#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/Component.hpp>
#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/IRenderer.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Renderer : public core_interface::IRenderer
	{
	public:
		Renderer(core_interface::Transform* transform, const core_interface::IModel* model);
		Renderer(core_interface::Transform* transform, const core_interface::IModel* model, const core_interface::Material& material);
		~Renderer();
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
