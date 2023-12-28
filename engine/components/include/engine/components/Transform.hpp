#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/ITransform.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Transform : public core_interface::ITransform
	{
	public:
		Transform(core_interface::IEngine* engine, core_interface::IScene* scene, const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));
		~Transform() = default;
		Transform(const Transform& transform);
		Transform& operator=(const Transform& transform);

		virtual core_interface::ITransform* clone() const override;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
