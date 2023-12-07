#include <glad/glad.h>
#include <graphic/Texture.hpp>
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

	unsigned int loadTextureFromFile(const std::filesystem::path& path)
	{
		stbi_set_flip_vertically_on_load(true);

		unsigned int textureID;
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
}
