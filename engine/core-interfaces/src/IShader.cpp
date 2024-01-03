#include <engine/core-interfaces/IShader.hpp>

#include <engine/utility/File.hpp>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace gam703::engine::core_interface
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

		unsigned int createVertexShader(const std::string& vertexCode)
		{
			const char* vShaderCode = vertexCode.c_str();
			unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex, 1, &vShaderCode, NULL);
			glCompileShader(vertex);
			checkCompileErrors(vertex, "VERTEX");

			return vertex;
		}

		unsigned int createFragmentShader(const std::string& fragmentCode)
		{
			const char* fShaderCode = fragmentCode.c_str();
			unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment, 1, &fShaderCode, NULL);
			glCompileShader(fragment);
			checkCompileErrors(fragment, "FRAGMENT");

			return fragment;
		}
	}

	IShader::IShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) : m_vertexShaderPath(vertexShaderPath), m_fragmentShaderPath(fragmentShaderPath)
	{
		createShaderProgram();
	}

	IShader::IShader(const IShader& shader) : m_vertexShaderPath(shader.m_vertexShaderPath), m_fragmentShaderPath(shader.m_fragmentShaderPath)
	{
		createShaderProgram();
	}

	IShader& IShader::operator=(const IShader& shader)
	{
		m_vertexShaderPath = shader.m_vertexShaderPath;
		m_fragmentShaderPath = shader.m_fragmentShaderPath;
		glDeleteProgram(m_id);
		createShaderProgram();
		return *this;
	}

	IShader::~IShader()
	{
		glDeleteProgram(m_id);
	}

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

	void IShader::createShaderProgram()
	{
		std::string vertexCode = utility::readFile(m_vertexShaderPath);
		std::string fragmentCode = utility::readFile(m_fragmentShaderPath);

		unsigned int vertex = createVertexShader(vertexCode);
		unsigned int fragment = createFragmentShader(fragmentCode);

		m_id = glCreateProgram();
		glAttachShader(m_id, vertex);
		glAttachShader(m_id, fragment);
		glLinkProgram(m_id);
		checkCompileErrors(m_id, "PROGRAM");

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		setDefaultValues();
	}

	void IShader::setDefaultValues() const
	{
		setColor(glm::vec3(1.0f, 1.0f, 1.0f));
		setFloat("material.shininess", 32.0f);
		setFloat("material.specularStrength", 0.5f);
	}
}
