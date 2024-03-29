#include <engine/graphic/Shader.hpp>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

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

	ShaderSource::ShaderSource(const std::string& sourceCode, int shaderType)
	{
		if (shaderType == GL_VERTEX_SHADER)
		{
			m_shaderID = createVertexShader(sourceCode);
		}
		else if (shaderType == GL_FRAGMENT_SHADER)
		{
			m_shaderID = createFragmentShader(sourceCode);
		}
	}

	ShaderSource::~ShaderSource()
	{
		glDeleteShader(m_shaderID);
	}

	Shader::Shader(ShaderSource* vertexShader, ShaderSource* fragmentShader) : m_vertex(vertexShader), m_fragment(fragmentShader)
	{
		createShaderProgram();
	}

	Shader::Shader(const Shader& shader) : m_vertex(shader.m_vertex), m_fragment(shader.m_fragment)
	{
		createShaderProgram();
	}

	Shader& Shader::operator=(const Shader& shader)
	{
		if (m_vertex != shader.m_vertex || m_fragment != shader.m_fragment)
		{
			m_vertex = shader.m_vertex;
			m_fragment = shader.m_fragment;
			glDeleteProgram(m_id);
			createShaderProgram();
		}
		return *this;
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
		use();
		glUniform1i(glGetUniformLocation(m_id, name.c_str()), value ? 1 : 0);
	}

	void Shader::setInt(const std::string& name, int value) const
	{
		use();
		glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
	}

	void Shader::setFloat(const std::string& name, float value) const
	{
		use();
		glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
	}

	void Shader::setVec2(const std::string& name, const glm::vec2& value) const
	{
		use();
		glUniform2fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::setVec2(const std::string& name, float x, float y) const
	{
		use();
		glUniform2f(glGetUniformLocation(m_id, name.c_str()), x, y);
	}

	void Shader::setVec3(const std::string& name, const glm::vec3& value) const
	{
		use();
		glUniform3fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::setVec3(const std::string& name, float x, float y, float z) const
	{
		use();
		glUniform3f(glGetUniformLocation(m_id, name.c_str()), x, y, z);
	}

	void Shader::setVec4(const std::string& name, const glm::vec4& value) const
	{
		use();
		glUniform4fv(glGetUniformLocation(m_id, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
	{
		use();
		glUniform4f(glGetUniformLocation(m_id, name.c_str()), x, y, z, w);
	}

	void Shader::setMat2(const std::string& name, const glm::mat2& mat) const
	{
		use();
		glUniformMatrix2fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::setMat3(const std::string& name, const glm::mat3& mat) const
	{
		use();
		glUniformMatrix3fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
	{
		use();
		glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::setDiffuseSampler(int index, int value) const
	{
		use();
		setInt("material.diffuseTexture", value);
	}

	void Shader::setSpecularSampler(int index, int value) const
	{
		use();
		setInt("material.specularTexture", value);
	}

	void Shader::setNormalSampler(int index, int value) const
	{
		use();
		setInt("normal", value);
	}

	void Shader::setHeightSampler(int index, int value) const
	{
		use();
		setInt("height", value);
	}

	void Shader::setColor(const glm::vec3& color) const
	{
		use();
		setVec3("material.color", color);
	}

	void Shader::setAmbientLight(const glm::vec3& color, float intensity) const
	{
		setVec3("ambientLight.color", color);
		setFloat("ambientLight.intensity", intensity);
	}

	void Shader::createShaderProgram()
	{
		m_id = glCreateProgram();
		glAttachShader(m_id, m_vertex->getShaderID());
		glAttachShader(m_id, m_fragment->getShaderID());
		glLinkProgram(m_id);
		checkCompileErrors(m_id, "PROGRAM");

		setDefaultValues();
	}

	void Shader::setDefaultValues() const
	{
		setColor(glm::vec3(1.0f, 1.0f, 1.0f));
		setFloat("material.shininess", 32.0f);
		setFloat("material.specularStrength", 0.5f);
	}
}
