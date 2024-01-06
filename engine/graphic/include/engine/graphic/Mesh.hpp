#ifndef GAM703_ENGINE_GRAPHIC_MESH_HPP
#define GAM703_ENGINE_GRAPHIC_MESH_HPP

#include <engine/graphic/Material.hpp>
#include <engine/graphic/Texture.hpp>

#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace gam703::engine::graphic
{
	/// @brief How many bones can influence vertex
	constexpr int MaxBoneInfluence = 4;

	/// @brief Vertex represent a point in a mesh
	struct Vertex
	{
		/// @brief Vertex position
		glm::vec3 m_position = glm::vec3();
		/// @brief Vertex normal
		glm::vec3 m_normal = glm::vec3();
		/// @brief Vertex texture coordinates
		glm::vec2 m_textureCoordinates = glm::vec2();
		/// @brief Vertex tangent
		glm::vec3 m_tangent = glm::vec3();
		/// @brief Vertex bitangent
		glm::vec3 m_bitangent = glm::vec3();
		/// @brief Vertex bone id
		int m_boneIDs[MaxBoneInfluence] = { 0 };
		/// @brief Vertex bone weight
		float m_weights[MaxBoneInfluence] = { 0 };
	};

	/// @brief Mesh is used in Model every Model is made of one or multiple Mesh
	class Mesh
	{
	public:
		/// @brief Create a Mesh
		/// @param vertices Mesh vertices
		/// @param indices Mesh vertices triangle indices
		/// @param textures Mesh textures
		Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<const Texture*>& textures);

		/// @brief Draw mesh with selected material
		/// @param material Material used to set texture indices
		void draw(const Material& material) const;

	private:
		/// @brief Setup mesh VAO, VBO, EBO
		void setupMesh();

		/// @brief VAO ID
		unsigned int m_vertexArrayObject = 0;
		/// @brief VBO ID
		unsigned int m_vertexBufferObject = 0;
		/// @brief EBO ID
		unsigned int m_elementBufferObject = 0;
		/// @brief List of all vertices
		std::vector<Vertex> m_vertices{};
		/// @brief List of all triangle indices
		std::vector<unsigned int> m_indices{};
		/// @brief List of all textures
		std::vector<const Texture*> m_textures{};
	};

} //gam703::engine::graphic

#endif //GAM703_ENGINE_GRAPHIC_MESH_HPP
