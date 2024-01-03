#include <engine/core-interfaces/IShader.hpp>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace gam703::engine::core_interface
{
	void IShader::use() const
	{
		glUseProgram(m_id);
	}

	void IShader::setBool(const std::string& name, bool value) const
	{
		use();
		glUniform1i(glGetUniformLocation(m_id, name.c_str()), value ? 1 : 0);
	}

	void IShader::setInt(const std::string& name, int value) const
	{
		use();
		glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
	}

	void IShader::setFloat(const std::string& name, float value) const
	{
		use();
		glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
	}

	void IShader::setVec2(const std::string& name, const glm::vec2& value) const
	{
		use();
		glUniform2fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void IShader::setVec2(const std::string& name, float x, float y) const
	{
		use();
		glUniform2f(glGetUniformLocation(m_id, name.c_str()), x, y);
	}

	void IShader::setVec3(const std::string& name, const glm::vec3& value) const
	{
		use();
		glUniform3fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void IShader::setVec3(const std::string& name, float x, float y, float z) const
	{
		use();
		glUniform3f(glGetUniformLocation(m_id, name.c_str()), x, y, z);
	}

	void IShader::setVec4(const std::string& name, const glm::vec4& value) const
	{
		use();
		glUniform4fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void IShader::setVec4(const std::string& name, float x, float y, float z, float w) const
	{
		use();
		glUniform4f(glGetUniformLocation(m_id, name.c_str()), x, y, z, w);
	}

	void IShader::setMat2(const std::string& name, const glm::mat2& mat) const
	{
		use();
		glUniformMatrix2fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void IShader::setMat3(const std::string& name, const glm::mat3& mat) const
	{
		use();
		glUniformMatrix3fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void IShader::setMat4(const std::string& name, const glm::mat4& mat) const
	{
		use();
		glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void IShader::setDiffuseSampler(int index, int value) const
	{
		use();
		setInt("material.diffuseTexture", value);
	}

	void IShader::setSpecularSampler(int index, int value) const
	{
		use();
		setInt("material.specularTexture", value);
	}

	void IShader::setNormalSampler(int index, int value) const
	{
		use();
		setInt("normal", value);
	}

	void IShader::setHeightSampler(int index, int value) const
	{
		use();
		setInt("height", value);
	}

	void IShader::setColor(const glm::vec3& color) const
	{
		use();
		setVec3("material.color", color);
	}
}
