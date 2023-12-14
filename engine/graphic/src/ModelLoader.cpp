#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <engine/graphic/ModelLoader.hpp>

#include <glm/glm.hpp>

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

		core_interface::ITexture::TextureType convertAITextureType(aiTextureType type)
		{
			switch (type)
			{
			case aiTextureType_DIFFUSE:
			{
				return core_interface::ITexture::TextureType::Diffuse;
			}
			case aiTextureType_SPECULAR:
			{
				return core_interface::ITexture::TextureType::Specular;
			}
			case aiTextureType_HEIGHT:
			{
				return core_interface::ITexture::TextureType::Height;
			}
			case aiTextureType_AMBIENT:
			{
				return core_interface::ITexture::TextureType::Normal;
			}
			default:
			{
				return core_interface::ITexture::TextureType::Undefined;
			}
			}
		}
	}

	ModelLoader::ModelLoader(core_interface::IResourceManager* resourceManager) : m_resourceManager(resourceManager)
	{
	}

	Model* ModelLoader::loadModel(const std::filesystem::path& path)
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path.string(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
		{
			std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
			return nullptr;
		}

		m_currentDirectory = path.parent_path();

		std::vector<Mesh> meshes = {};
		processNode(meshes, scene->mRootNode, scene);

		return new Model(meshes);
	}

	void ModelLoader::processNode(std::vector<Mesh>& meshes, const aiNode* node, const aiScene* scene)
	{
		for (unsigned int i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(processMesh(mesh, scene));
		}

		for (unsigned int i = 0; i < node->mNumChildren; i++)
		{
			processNode(meshes, node->mChildren[i], scene);
		}
	}

	Mesh ModelLoader::processMesh(const aiMesh* mesh, const aiScene* scene)
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

		if (textures.size() == 0)
		{
			textures.push_back(m_resourceManager->getWhiteTexture());
		}

		return Mesh(vertices, indices, textures);
	}

	void ModelLoader::loadMaterialTextures(std::vector<const core_interface::ITexture*>& textures, const aiMaterial* mat, aiTextureType type)
	{
		for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
		{
			aiString str;
			mat->GetTexture(type, i, &str);

			textures.push_back(m_resourceManager->getTexture(m_currentDirectory / str.C_Str(), convertAITextureType(type)));
		}
	}

}
