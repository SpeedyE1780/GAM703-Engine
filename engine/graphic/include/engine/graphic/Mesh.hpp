#ifndef GAM703_ENGINE_GRAPHIC_MESH_HPP
#define GAM703_ENGINE_GRAPHIC_MESH_HPP

#include <engine/core-interfaces/Material.hpp>
#include <engine/core-interfaces/ITexture.hpp>

#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace gam703::engine::graphic
{
	constexpr int MaxBoneInfluence = 4;

	struct Vertex
	{
		glm::vec3 m_position = glm::vec3();
		glm::vec3 m_normal = glm::vec3();
		glm::vec2 m_textureCoordinates = glm::vec2();
		glm::vec3 m_tangent = glm::vec3();
		glm::vec3 m_bitangent = glm::vec3();
		int m_boneIDs[MaxBoneInfluence] = { 0 };
		float m_weights[MaxBoneInfluence] = { 0 };
	};

	class Mesh
	{
	public:
		Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<const core_interface::ITexture*>& textures);
		void draw(const core_interface::Material& material) const;

	private:
		void setupMesh();

		unsigned int m_vertexArrayObject = 0;
		unsigned int m_vertexBufferObject = 0;
		unsigned int m_elementBufferObject = 0;
		std::vector<Vertex> m_vertices{};
		std::vector<unsigned int> m_indices{};
		std::vector<const core_interface::ITexture*> m_textures{};
	};

} //gam703::engine::graphic

#endif //GAM703_ENGINE_GRAPHIC_MESH_HPP
