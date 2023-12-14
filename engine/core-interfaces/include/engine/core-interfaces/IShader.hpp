#ifndef GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class IShader
	{
	public:
		virtual ~IShader() = default;
		virtual void setDiffuseSampler(int index, int value) const = 0;
		virtual void setSpecularSampler(int index, int value) const = 0;
		virtual void setNormalSampler(int index, int value) const = 0;
		virtual void setHeightSampler(int index, int value) const = 0;
		virtual void setColor(const glm::vec3& color) const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP
