#ifndef GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class ITransform;

	class IScene
	{
	public:
		virtual ~IScene() = default;

		virtual ITransform* addTransform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1)) = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISCENE_HPP
