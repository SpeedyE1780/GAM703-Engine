#ifndef GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP

#include <glm/glm.hpp>

#include <string>

namespace gam703::engine::core_interface
{
	class IShader
	{
	public:
		virtual ~IShader() = default;
		virtual void use() const = 0;
		virtual unsigned int getId() const = 0;
		virtual void setBool(const std::string& name, bool value) const = 0;
		virtual void setInt(const std::string& name, int value) const = 0;
		virtual void setFloat(const std::string& name, float value) const = 0;
		virtual void setVec2(const std::string& name, const glm::vec2& value) const = 0;
		virtual void setVec2(const std::string& name, float x, float y) const = 0;
		virtual void setVec3(const std::string& name, const glm::vec3& value) const = 0;
		virtual void setVec3(const std::string& name, float x, float y, float z) const = 0;
		virtual void setVec4(const std::string& name, const glm::vec4& value) const = 0;
		virtual void setVec4(const std::string& name, float x, float y, float z, float w) const = 0;
		virtual void setMat2(const std::string& name, const glm::mat2& mat) const = 0;
		virtual void setMat3(const std::string& name, const glm::mat3& mat) const = 0;
		virtual void setMat4(const std::string& name, const glm::mat4& mat) const = 0;
		virtual void setDiffuseSampler(int index, int value) const = 0;
		virtual void setSpecularSampler(int index, int value) const = 0;
		virtual void setNormalSampler(int index, int value) const = 0;
		virtual void setHeightSampler(int index, int value) const = 0;
		virtual void setColor(const glm::vec3& color) const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP
