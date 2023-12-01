#ifndef GAM703_ENGINE_GRAPHIC_MESH_HPP
#define GAM703_ENGINE_GRAPHIC_MESH_HPP

#include <glm/glm.hpp>
#include <graphic/Shader.fwd.hpp>

#include <string>
#include <vector>

namespace gam703::engine::graphic
{
	constexpr int MaxBoneInfluence = 4;

	struct Vertex
	{
		glm::vec3 m_position;
		glm::vec3 m_normal;
		glm::vec2 m_textureCoordinates;
		glm::vec3 m_tangent;
		glm::vec3 m_bitangent;
		int m_boneIDs[MaxBoneInfluence];
		float m_weights[MaxBoneInfluence];
	};

	struct Texture
	{
		enum class TextureType
		{
			Diffuse,
			Specular,
			Normal,
			Height
		};

		unsigned int m_id;
		std::string m_type;
		std::string path;
	};

	class Mesh
	{

	public:
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		void Draw(const Shader& shader) const;

	private:
		void setupMesh();

		unsigned int m_vertexArrayObject;
		unsigned int m_vertexBufferObject;
		unsigned int m_elementBufferObject;
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;
		std::vector<Texture> m_textures;

	};

} //gam703::engine::graphic

#endif //GAM703_ENGINE_GRAPHIC_MESH_HPP
