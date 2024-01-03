#include <engine/graphic/Shader.hpp>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

#include <engine/utility/File.hpp>

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

	Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) : m_vertexShaderPath(vertexShaderPath), m_fragmentShaderPath(fragmentShaderPath)
	{
		createShaderProgram();
	}

	Shader::Shader(const Shader& shader) : m_vertexShaderPath(shader.m_vertexShaderPath), m_fragmentShaderPath(shader.m_fragmentShaderPath)
	{
		createShaderProgram();
	}

	Shader& Shader::operator=(const Shader& shader)
	{
		m_vertexShaderPath = shader.m_vertexShaderPath;
		m_fragmentShaderPath = shader.m_fragmentShaderPath;
		glDeleteProgram(m_id);
		createShaderProgram();
		return *this;
	}

	void Shader::createShaderProgram()
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

	void Shader::setDefaultValues() const
	{
		setColor(glm::vec3(1.0f, 1.0f, 1.0f));
		setFloat("material.shininess", 32.0f);
		setFloat("material.specularStrength", 0.5f);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_id);
	}

	Shader createDefaultShader()
	{
		return Shader("resources/Shaders/Default.vert", "resources/Shaders/Default.frag");
	}
}
