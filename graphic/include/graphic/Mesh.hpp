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
		glm::vec3 m_position = glm::vec3();
		glm::vec3 m_normal = glm::vec3();
		glm::vec2 m_textureCoordinates = glm::vec2();
		glm::vec3 m_tangent = glm::vec3();
		glm::vec3 m_bitangent = glm::vec3();
		int m_boneIDs[MaxBoneInfluence] = { 0 };
		float m_weights[MaxBoneInfluence] = { 0 };
	};

	struct Texture
	{
		enum class TextureType
		{
			Undefined,
			Diffuse,
			Specular,
			Normal,
			Height
		};

		unsigned int m_id= 0;
		TextureType m_type = TextureType::Undefined;
		std::string path = "";
	};

	class Mesh
	{

	public:
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		void draw(const Shader& shader) const;

	private:
		void setupMesh();

		unsigned int m_vertexArrayObject = 0;
		unsigned int m_vertexBufferObject = 0;
		unsigned int m_elementBufferObject = 0;
		std::vector<Vertex> m_vertices{};
		std::vector<unsigned int> m_indices{};
		std::vector<Texture> m_textures{};

	};

} //gam703::engine::graphic

#endif //GAM703_ENGINE_GRAPHIC_MESH_HPP
