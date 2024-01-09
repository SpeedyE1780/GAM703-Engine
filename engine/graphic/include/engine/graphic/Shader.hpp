#ifndef GAM703_ENGINE_GRAPHIC_SHADER_HPP
#define GAM703_ENGINE_GRAPHIC_SHADER_HPP

#include <engine/graphic/Config.hpp>

#include <glm/glm.hpp>

#include <string>

namespace gam703::engine::graphic
{
	/// @brief ShaderSource wraps open gl shaders to optimize reading shader source
	class ENGINE_GRAPHIC_API ShaderSource
	{
	public:
		/// @brief Create a gl shader using the provided source code
		/// @param sourceCode The shader source code
		/// @param shaderType The type of shader (eg: Vertex/Fragment/Geometry)
		ShaderSource(const std::string& sourceCode, int shaderType);

		/// @brief Delete the shader
		~ShaderSource();

		/// @brief Get the gl shader id
		/// @return The gl shader id
		unsigned int getShaderID() const { return m_shaderID; }

	private:
		/// @brief The gl shader id
		int m_shaderID = 0;
	};

	/// @brief Shader contains all information passed to GPU to render 3D model
	class ENGINE_GRAPHIC_API Shader
	{
	public:
		/// @brief Create Shader from vertex and fragment shader
		/// @param vertexShaderPath Vertex Shader source code path
		/// @param fragmentShaderPath Fragment Shader source code path
		Shader(ShaderSource* vertexShader, ShaderSource* fragmentShader);

		/// @brief Create shader using other shader vertex and fragment shader
		/// @param shader Contains vertex shader source and fragment shader source path
		Shader(const Shader& shader);

		/// @brief Create shader using other shader vertex and fragment shader
		/// @param shader Contains vertex shader source and fragment shader source path
		/// @return New shader using different vertex and fragment source
		Shader& operator=(const Shader& shader);

		/// @brief Destroy shader program
		~Shader();

		/// @brief Set shader to active program in OpenGL
		void use() const;

		/// @brief Set bool uniform
		/// @param name Uniform name
		/// @param value Uniform value
		void setBool(const std::string& name, bool value) const;

		/// @brief Set int uniform
		/// @param name Uniform name
		/// @param value Uniform value
		void setInt(const std::string& name, int value) const;

		/// @brief Set float uniform
		/// @param name Uniform name
		/// @param value Uniform value
		void setFloat(const std::string& name, float value) const;

		/// @brief Set vec2 uniform
		/// @param name Uniform name
		/// @param value Uniform value
		void setVec2(const std::string& name, const glm::vec2& value) const;

		/// @brief Set vec2 uniform
		/// @param name Uniform name
		/// @param x vec2 x component
		/// @param y vec2 y component
		void setVec2(const std::string& name, float x, float y) const;

		/// @brief Set vec3 uniform
		/// @param name Uniform name
		/// @param value Uniform value
		void setVec3(const std::string& name, const glm::vec3& value) const;

		/// @brief Set vec3 uniform
		/// @param name Uniform name
		/// @param x vec3 x component
		/// @param y vec3 y component
		/// @param z vec3 z component
		void setVec3(const std::string& name, float x, float y, float z) const;

		/// @brief Set vec4 uniform
		/// @param name Uniform name
		/// @param value Uniform value
		void setVec4(const std::string& name, const glm::vec4& value) const;

		/// @brief Set vec4 uniform
		/// @param name Uniform name
		/// @param x vec4 x component
		/// @param y vec4 y component
		/// @param z vec4 z component
		/// @param w vec4 w component
		void setVec4(const std::string& name, float x, float y, float z, float w) const;

		/// @brief Set mat2 uniform
		/// @param name Uniform name
		/// @param mat Uniform value
		void setMat2(const std::string& name, const glm::mat2& mat) const;

		/// @brief Set mat3 uniform
		/// @param name Uniform name
		/// @param mat Uniform value
		void setMat3(const std::string& name, const glm::mat3& mat) const;

		/// @brief Set mat4 uniform
		/// @param name Uniform name
		/// @param mat Uniform value
		void setMat4(const std::string& name, const glm::mat4& mat) const;

		/// @brief Set diffuse sampler
		/// @param index Diffuse index in shader
		/// @param value Sampler index in OpenGL
		void setDiffuseSampler(int index, int value) const;

		/// @brief Set specular sampler
		/// @param index Specular index in shader
		/// @param value Sampler index in OpenGL
		void setSpecularSampler(int index, int value) const;

		/// @brief Set normal sampler
		/// @param index Normal index in shader
		/// @param value Sampler index in OpenGL
		void setNormalSampler(int index, int value) const;

		/// @brief Set height sampler
		/// @param index Height index in shader
		/// @param value Sampler index in OpenGL
		void setHeightSampler(int index, int value) const;

		/// @brief Set color uniform
		/// @param color Color value
		void setColor(const glm::vec3& color) const;

		/// @brief Set ambient light uniform
		/// @param color ambient light color
		/// @param intensity ambient light intensity
		void setAmbientLight(const glm::vec3& color, float intensity) const;

	private:
		/// @brief Load shader sources and create shader program
		void createShaderProgram();

		/// @brief Set shader default uniform values
		void setDefaultValues() const;

		/// @brief Shader program id
		unsigned int m_id = 0;
		/// @brief Vertex shader id
		ShaderSource* m_vertex;
		/// @brief Fragment shader id
		ShaderSource* m_fragment;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_SHADER_HPP
