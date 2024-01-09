#ifndef GAM703_ENGINE_GRAPHIC_MATERIAL_HPP
#define GAM703_ENGINE_GRAPHIC_MATERIAL_HPP

#include <engine/graphic/Config.hpp>
#include <engine/graphic/Shader.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::graphic
{
	/// @brief Material used to set 3D model rendering properties
	class ENGINE_GRAPHIC_API Material
	{
	public:
		/// @brief Create material with given shader
		/// @param shader Shader that will be used to create material shader
		Material(const Shader& shader);

		/// @brief Create material based on given material
		/// @param material Material that will be used to create material
		Material(const Material& material);

		/// @brief Update material based on given material
		/// @param material Material that will be used to update material
		/// @return this material with given material properties
		Material& operator=(const Material& material);

		/// @brief Get material color
		/// @return The material color
		const glm::vec3& getColor() const { return m_color; }

		/// @brief Set material color
		/// @param color New material color
		void setColor(const glm::vec3& color);

		/// @brief Set diffuse texture in shader
		/// @param diffuseIndex Diffuse index in shader
		/// @param textureIndex Texture index in OpenGL
		void setDiffuseTexture(int diffuseIndex, int textureIndex) const;

		/// @brief Set specular texture in shader
		/// @param specularIndex Specular index in shader
		/// @param textureIndex Texture index in OpenGL
		void setSpecularTexture(int specularIndex, int textureIndex) const;

		/// @brief Set normal texture in shader
		/// @param normalIndex Normal index in shader
		/// @param textureIndex Texture index in OpenGL
		void setNormalTexture(int normalIndex, int textureIndex) const;

		/// @brief Set height texture in shader
		/// @param heightIndex Height index in shader
		/// @param textureIndex Texture index in OpenGL
		void setHeightTexture(int heightIndex, int textureIndex) const;

		/// @brief Get material shader
		/// @return Material Shader
		Shader& getShader() { return m_shader; }

		/// @brief Get material shader
		/// @return Material shader
		const Shader& getShader() const { return m_shader; }

	private:
		/// @brief Material tint color
		glm::vec3 m_color = glm::vec3(1, 1, 1);
		/// @brief Shader used to draw 3D model
		Shader m_shader;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MATERIAL_HPP
