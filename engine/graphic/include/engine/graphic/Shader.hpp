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

	private:
		void createShaderProgram();
		void setDefaultValues() const;

		std::string m_vertexShaderPath;
		std::string m_fragmentShaderPath;
	};

	ENGINE_GRAPHIC_API Shader createDefaultShader();
}

#endif //GAM703_ENGINE_GRAPHIC_SHADER_HPP
