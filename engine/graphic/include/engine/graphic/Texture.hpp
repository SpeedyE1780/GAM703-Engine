#ifndef GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
#define GAM703_ENGINE_GRAPHIC_TEXTURE_HPP

#include <engine/graphic/Config.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	/// @brief Texture image used on models
	class ENGINE_GRAPHIC_API Texture
	{
	public:
		/// @brief Texture type
		enum class TextureType
		{
			/// @brief Unkown type
			Undefined,
			/// @brief Diffuse map
			Diffuse,
			/// @brief Specular map
			Specular,
			/// @brief Normal map
			Normal,
			/// @brief Height map
			Height
		};

		/// @brief Create texture with id and type
		/// @param id Texture OpenGL id
		/// @param type Texture map type
		Texture(unsigned int id, TextureType type);

		/// @brief Delete texture from OpenGl
		~Texture();

		/// @brief Get texture ID
		/// @return OpenGL texture ID
		unsigned int getID() const { return m_id; }

		/// @brief Get texture type
		/// @return Texture type
		TextureType getType() const { return m_type; }

	private:
		/// @brief OpenGL texture ID
		unsigned int m_id = 0;
		/// @brief Texture type
		TextureType m_type = TextureType::Undefined;
	};

	/// @brief Load texture from file path and return OpenGL ID
	/// @param path Path of texture
	/// @return OpenGL texture ID
	ENGINE_GRAPHIC_API unsigned int loadTextureFromFile(const std::filesystem::path& path);

	/// @brief Create 1x1 white texture
	/// @return 1x1 white texture
	ENGINE_GRAPHIC_API unsigned int createWhiteTexture();
}

#endif //GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
