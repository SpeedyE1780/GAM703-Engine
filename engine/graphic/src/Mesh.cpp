#include <engine/graphic/Mesh.hpp>

#include <glad/glad.h>

namespace gam703::engine::graphic
{
	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<const Texture*>& textures) : m_vertices(vertices), m_indices(indices), m_textures(textures)
	{
		setupMesh();
	}

	void Mesh::draw(const Material& material) const
	{
		unsigned int diffuseIndex = 1;
		unsigned int specularIndex = 1;
		unsigned int normalIndex = 1;
		unsigned int heightIndex = 1;

		for (unsigned int i = 0; i < m_textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			switch (m_textures[i]->getType())
			{
			case Texture::TextureType::Diffuse:
			{
				material.setDiffuseTexture(diffuseIndex, i);
				diffuseIndex++;
				break;
			}
			case Texture::TextureType::Specular:
			{
				material.setSpecularTexture(specularIndex, i);
				specularIndex++;
				break;
			}
			case Texture::TextureType::Normal:
			{
				material.setNormalTexture(normalIndex, i);
				normalIndex++;
				break;
			}
			case Texture::TextureType::Height:
			{
				material.setHeightTexture(heightIndex, i);
				heightIndex++;
				break;
			}
			case Texture::TextureType::Undefined:
			{
				break;
			}
			}

			glBindTexture(GL_TEXTURE_2D, m_textures[i]->getID());
		}

		glBindVertexArray(m_vertexArrayObject);
		glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_indices.size()), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
	}

	void Mesh::setupMesh()
	{
		glGenVertexArrays(1, &m_vertexArrayObject);
		glGenBuffers(1, &m_vertexBufferObject);
		glGenBuffers(1, &m_elementBufferObject);

		glBindVertexArray(m_vertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_textureCoordinates));

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_tangent));

		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_bitangent));

		glEnableVertexAttribArray(5);
		glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, m_boneIDs));

		glEnableVertexAttribArray(6);
		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_weights));

		glBindVertexArray(0);
	}
}
