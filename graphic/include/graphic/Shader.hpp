#ifndef GAM703_ENGINE_GRAPHIC_SHADER_HPP
#define GAM703_ENGINE_GRAPHIC_SHADER_HPP

#include <glm/glm.hpp>
#include <string>

namespace gam703::engine::graphic
{
	class Shader
	{
	public:
		Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		~Shader();
		void use() const;
		unsigned int getId() const { return m_id; }
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
	private:
		unsigned int m_id = 0;
	};

	Shader createDefaultShader();
}

#endif //GAM703_ENGINE_GRAPHIC_SHADER_HPP
