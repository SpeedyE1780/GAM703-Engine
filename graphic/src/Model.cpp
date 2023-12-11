#include <graphic/Model.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <graphic/Texture.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace gam703::engine::graphic
{
	namespace
	{
		glm::vec2 convertAIVectorToGLM(const aiVector2D& aiVector)
		{
			return glm::vec2(aiVector.x, aiVector.y);
		}

		glm::vec3 convertAIVectorToGLM(const aiVector3D& aiVector)
		{
			return glm::vec3(aiVector.x, aiVector.y, aiVector.z);
		}

		Texture::TextureType convertAITextureType(aiTextureType type)
		{
			switch (type)
			{
			case aiTextureType_DIFFUSE:
			{
				return Texture::TextureType::Diffuse;
			}
			case aiTextureType_SPECULAR:
			{
				return Texture::TextureType::Specular;
			}
			case aiTextureType_HEIGHT:
			{
				return Texture::TextureType::Height;
			}
			case aiTextureType_AMBIENT:
			{
				return Texture::TextureType::Normal;
			}
			default:
			{
				return Texture::TextureType::Undefined;
			}
			}
		}
	}

	Model::Model(const std::filesystem::path& path, core_interface::IResourceManager* resourceManager) : m_directory(path.parent_path()), m_resourceManager(resourceManager)
	{
		loadModel(path);
	}

	void Model::draw(const Shader& shader) const
	{
		std::for_each(begin(m_meshes), end(m_meshes), [&shader](const Mesh& mesh) { mesh.draw(shader); });
	}

	void Model::loadModel(const std::filesystem::path& path)
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path.string(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
		{
			std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
			return;
		}

		processNode(scene->mRootNode, scene);
	}

	void Model::processNode(const aiNode* node, const aiScene* scene)
	{
		for (unsigned int i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			m_meshes.push_back(processMesh(mesh, scene));
		}

		for (unsigned int i = 0; i < node->mNumChildren; i++)
		{
			processNode(node->mChildren[i], scene);
		}
	}

	Mesh Model::processMesh(const aiMesh* mesh, const aiScene* scene)
	{
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			Vertex vertex{};

			vertex.m_position = convertAIVectorToGLM(mesh->mVertices[i]);

			if (mesh->HasNormals())
			{
				vertex.m_normal = convertAIVectorToGLM(mesh->mNormals[i]);
			}

			if (mesh->mTextureCoords[0])
			{
				vertex.m_textureCoordinates = convertAIVectorToGLM(mesh->mTextureCoords[0][i]);
				vertex.m_tangent = convertAIVectorToGLM(mesh->mTangents[i]);
				vertex.m_bitangent = convertAIVectorToGLM(mesh->mBitangents[i]);
			}

			vertices.push_back(vertex);
		}

		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
			{
				indices.push_back(mesh->mFaces[i].mIndices[j]);
			}
		}

		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		std::vector<const core_interface::ITexture*> textures{};
		loadMaterialTextures(textures, material, aiTextureType_DIFFUSE);
		loadMaterialTextures(textures, material, aiTextureType_SPECULAR);
		loadMaterialTextures(textures, material, aiTextureType_HEIGHT);
		loadMaterialTextures(textures, material, aiTextureType_AMBIENT);

		return Mesh(vertices, indices, textures);
	}

	void Model::loadMaterialTextures(std::vector<const core_interface::ITexture*>& textures, const aiMaterial* mat, aiTextureType type) const
	{
		for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
		{
			aiString str;
			mat->GetTexture(type, i, &str);

			textures.push_back(m_resourceManager->getTexture(m_directory/ str.C_Str(), convertAITextureType(type)));
		}
	}
}
