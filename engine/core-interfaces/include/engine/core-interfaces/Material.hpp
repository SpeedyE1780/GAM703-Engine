#ifndef GAM703_ENGINE_CORE_INTERFACES_IMATERIAL_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IMATERIAL_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Shader.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Material
	{
	public:
		Material();
		Material(const core_interface::Shader& shader);
		Material(const Material& material);
		Material& operator=(const Material& material);

		const glm::vec3& getColor() const { return m_color; }
		void setColor(const glm::vec3& color);

		void setDiffuseTexture(int diffuseIndex, int textureIndex) const;
		void setSpecularTexture(int specularIndex, int textureIndex) const;
		void setNormalTexture(int normalIndex, int textureIndex) const;
		void setHeightTexture(int heightIndex, int textureIndex) const;
		Shader* getShader() { return &m_shader; }
		const Shader* getShader() const { return &m_shader; }

	private:
		glm::vec3 m_color = glm::vec3(1, 1, 1);
		core_interface::Shader m_shader;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IMATERIAL_HPP
