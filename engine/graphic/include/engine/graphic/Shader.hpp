#ifndef GAM703_ENGINE_GRAPHIC_SHADER_HPP
#define GAM703_ENGINE_GRAPHIC_SHADER_HPP

#include <engine/core-interfaces/IShader.hpp>

#include <engine/graphic/Config.hpp>

#include <glm/glm.hpp>

#include <string>

namespace gam703::engine::graphic
{
	class ENGINE_GRAPHIC_API Shader : public core_interface::IShader
	{
	public:
		Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		Shader(const Shader& shader);
		Shader& operator=(const Shader& shader);
		~Shader();
		virtual void use() const override;
		virtual unsigned int getId() const override { return m_id; }
		virtual void setBool(const std::string& name, bool value) const override;
		virtual void setInt(const std::string& name, int value) const override;
		virtual void setFloat(const std::string& name, float value) const override;
		virtual void setVec2(const std::string& name, const glm::vec2& value) const override;
		virtual void setVec2(const std::string& name, float x, float y) const override;
		virtual void setVec3(const std::string& name, const glm::vec3& value) const override;
		virtual void setVec3(const std::string& name, float x, float y, float z) const override;
		virtual void setVec4(const std::string& name, const glm::vec4& value) const override;
		virtual void setVec4(const std::string& name, float x, float y, float z, float w) const override;
		virtual void setMat2(const std::string& name, const glm::mat2& mat) const override;
		virtual void setMat3(const std::string& name, const glm::mat3& mat) const override;
		virtual void setMat4(const std::string& name, const glm::mat4& mat) const override;
		virtual void setDiffuseSampler(int index, int value) const override;
		virtual void setSpecularSampler(int index, int value) const override;
		virtual void setNormalSampler(int index, int value) const override;
		virtual void setHeightSampler(int index, int value) const override;
		virtual void setColor(const glm::vec3& color) const override;
	private:
		void createShaderProgram();
		void setDefaultValues();

		unsigned int m_id = 0;
		std::string m_vertexShaderPath;
		std::string m_fragmentShaderPath;
	};

	ENGINE_GRAPHIC_API Shader createDefaultShader();
}

#endif //GAM703_ENGINE_GRAPHIC_SHADER_HPP
