#include <graphic/Shader.hpp>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <utility/File.hpp>

#include <iostream>

namespace gam703::engine::graphic
{
	namespace
	{
		// utility function for checking shader compilation/linking errors.
		// ------------------------------------------------------------------------
		void checkCompileErrors(unsigned int shader, std::string type)
		{
			int success;
			char infoLog[1024];
			if (type != "PROGRAM")
			{
				glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
				if (!success)
				{
					glGetShaderInfoLog(shader, 1024, NULL, infoLog);
					std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
						<< infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
				}
			}
			else
			{
				glGetProgramiv(shader, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(shader, 1024, NULL, infoLog);
					std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
						<< infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
				}
			}
		}
	}

	Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		std::string vertexCode = utility::readFile(vertexShaderPath);
		std::string fragmentCode = utility::readFile(fragmentShaderPath);

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		unsigned int vertex = 0, fragment = 0;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");

		m_id = glCreateProgram();
		glAttachShader(m_id, vertex);
		glAttachShader(m_id, fragment);
		glLinkProgram(m_id);
		checkCompileErrors(m_id, "PROGRAM");

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_id);
	}

	void Shader::use() const
	{
		glUseProgram(m_id);
	}

	void Shader::setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(m_id, name.c_str()), value ? 1 : 0);
	}

	void Shader::setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
	}

	void Shader::setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
	}

	void Shader::setVec2(const std::string& name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::setVec2(const std::string& name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(m_id, name.c_str()), x, y);
	}

	void Shader::setVec3(const std::string& name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::setVec3(const std::string& name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(m_id, name.c_str()), x, y, z);
	}

	void Shader::setVec4(const std::string& name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
	{
		glUniform4f(glGetUniformLocation(m_id, name.c_str()), x, y, z, w);
	}

	void Shader::setMat2(const std::string& name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::setMat3(const std::string& name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::setDiffuseSampler(int index, int value) const
	{
		setInt("diffuse", value);
	}

	void Shader::setSpecularSampler(int index, int value) const
	{
		setInt("specular", value);
	}

	void Shader::setNormalSampler(int index, int value) const
	{
		setInt("normal", value);
	}

	void Shader::setHeightSampler(int index, int value) const
	{
		setInt("height", value);
	}

	Shader createDefaultShader()
	{
		return Shader("resources/Shaders/Default.vert", "resources/Shaders/Default.frag");
	}
}
