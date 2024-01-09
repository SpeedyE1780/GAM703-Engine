#ifndef GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP

#include <engine/graphic/ModelLoader.hpp>
#include <engine/graphic/Shader.hpp>

#include <map>
#include <memory>

namespace gam703::engine::core
{
	/// @brief ResourceManager manages loading models and textures
	class ResourceManager
	{
	public:
		/// @brief Create a resource manager
		ResourceManager();
		~ResourceManager() = default;
		ResourceManager(const ResourceManager& other) = delete;
		ResourceManager& operator=(const ResourceManager& other) = delete;
		
		/// @brief Get/Load a texture using its file path
		/// @param path The texture file path
		/// @param type The texture type used when loading the texture
		/// @return The loaded/newly added texture or nullptr if it couldn't be found
		const graphic::Texture* getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type);

		/// @brief Return a 1x1 white texture to prevent 3D objects with no texture to be black
		/// @return A 1x1 white texture
		const graphic::Texture* getWhiteTexture();

		/// @brief Get/Load a model using its file path
		/// @param path The model file path
		/// @return The loaded/newly added model or nullptr if it couldn't be found
		const graphic::Model* getModel(const std::filesystem::path& path);

		/// @brief Get/Load a shader using its source code
		/// @param vertexSource Vertex shader source code
		/// @param fragmentSource Fragment shader source code
		/// @return The loaded/newly added shader or nullptr if it couldn't be found
		graphic::Shader* getShader(const std::filesystem::path& vertexSource, const std::filesystem::path& fragmentSource);

		/// @brief Return the default engine shader
		/// @return getShader("resources/Shaders/Default.vert", "resources/Shaders/Default.frag")
		graphic::Shader* getDefaultShader();

	private:
		/// @brief Get/Load a shader's source code
		/// @param shaderSourcePath The shader source code path
		/// @param shaderType The type of shader (eg: Vertex/Fragment/Geometry)
		/// @return A glShader to create a shader
		graphic::ShaderSource* getShaderSource(const std::filesystem::path& shaderSourcePath, int shaderType);

		/// @brief The model loader class used to load models from file
		graphic::ModelLoader m_modelLoader;
		/// @brief List of all loaded textures
		std::map<std::filesystem::path, std::unique_ptr<graphic::Texture>> m_textures{};
		/// @brief List of all loaded models
		std::map<std::filesystem::path, std::unique_ptr<graphic::Model>> m_models{};
		/// @brief List of all loaded shaders
		std::map<std::string, std::unique_ptr<graphic::Shader>> m_shaders;
		/// @brief List of all loaded vertex/fragment shaders
		std::map<std::filesystem::path, std::unique_ptr<graphic::ShaderSource>> m_shaderSources{};
	};
}

#endif // GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
