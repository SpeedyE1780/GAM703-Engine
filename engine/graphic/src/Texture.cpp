#include <engine/graphic/Texture.hpp>

#include <glad/glad.h>

#include <stb/stb_image.h>

#include <iostream>
#include <string>

namespace gam703::engine::graphic
{
	namespace
	{
		GLenum getTextureFormat(int numberOfComponents)
		{
			if (numberOfComponents == 1)
				return GL_RED;
			else if (numberOfComponents == 3)
				return GL_RGB;
			else if (numberOfComponents == 4)
				return GL_RGBA;

			return GL_RED;
		}
	}

	Texture::Texture(unsigned int id, TextureType type) : m_id(id), m_type(type)
	{
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_id);
	}

	unsigned int loadTextureFromFile(const std::filesystem::path& path)
	{
		stbi_set_flip_vertically_on_load(true);

		unsigned int textureID = 0;
		glGenTextures(1, &textureID);

		int width = 0, height = 0, components = 0;

		if (unsigned char* data = stbi_load(path.string().c_str(), &width, &height, &components, 0))
		{
			GLenum format = getTextureFormat(components);

			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else
		{
			std::cout << "Texture failed to load at path: " << path << std::endl;
		}

		return textureID;
	}

	unsigned int createWhiteTexture()
	{
		unsigned int textureID = 0;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		GLubyte texData[] = { 255, 255, 255, 255 };
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
		return textureID;
	}
}
