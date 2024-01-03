#ifndef GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP

#include <engine/core-interfaces/Config.hpp>

#include <glm/glm.hpp>

#include <string>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API IShader
	{
	public:
		virtual ~IShader() = default;
		void use() const;
		unsigned int getId() const;
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		void setVec2(const std::string& name, const glm::vec2& value) const;
		void setVec2(const std::string& name, float x, float y) const;
		void setVec3(const std::string& name, const glm::vec3& value) const;
		void setVec3(const std::string& name, float x, float y, float z) const;
		void setVec4(const std::string& name, const glm::vec4& value) const;
		void setVec4(const std::string& name, float x, float y, float z, float w) const;
		void setMat2(const std::string& name, const glm::mat2& mat) const;
		void setMat3(const std::string& name, const glm::mat3& mat) const;
		void setMat4(const std::string& name, const glm::mat4& mat) const;
		void setDiffuseSampler(int index, int value) const;
		void setSpecularSampler(int index, int value) const;
		void setNormalSampler(int index, int value) const;
		void setHeightSampler(int index, int value) const;
		void setColor(const glm::vec3& color) const;

	protected:
		unsigned int m_id = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ISHADER_HPP
