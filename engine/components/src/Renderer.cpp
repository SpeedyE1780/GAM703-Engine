#include <engine/components/Renderer.hpp>

#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::components
{
	Renderer::Renderer(core_interface::Transform* transform, const core_interface::IModel* model) : core_interface::IRenderer(transform, model)
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::Renderer(core_interface::Transform* transform, const core_interface::IModel* model, const core_interface::Material& material) : core_interface::IRenderer(transform, model, material)
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::~Renderer()
	{
		getScene()->getSceneRenderer()->removeRenderer(this);
	}
}
