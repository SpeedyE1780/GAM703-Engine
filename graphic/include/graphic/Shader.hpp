#ifndef GAM703_ENGINE_GRAPHIC_SHADER_HPP
#define GAM703_ENGINE_GRAPHIC_SHADER_HPP

#include <core-interfaces/IShader.hpp>
#include <graphic/Config.hpp>
#include <glm/glm.hpp>

#include <string>

namespace gam703::engine::graphic
{
	class GRAPHIC_API Shader : public core_interface::IShader
	{
	public:
		Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		Shader(const Shader& shader);
		Shader& operator=(const Shader& shader);
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
		virtual void setDiffuseSampler(int index, int value) const override;
		virtual void setSpecularSampler(int index, int value) const override;
		virtual void setNormalSampler(int index, int value) const override;
		virtual void setHeightSampler(int index, int value) const override;
	private:
		void createShaderProgram();

		unsigned int m_id = 0;
		std::string m_vertexShaderPath;
		std::string m_fragmentShaderPath;
	};

	GRAPHIC_API Shader createDefaultShader();
}

#endif //GAM703_ENGINE_GRAPHIC_SHADER_HPP
