#ifndef GAM703_ENGINE_GRAPHIC_MODEL_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_HPP

#include <graphic/Mesh.hpp>
#include <graphic/Shader.fwd.hpp>

#include <string>
#include <vector>
#include <filesystem>

struct aiNode;
struct aiMesh;
struct aiScene;
struct aiMaterial;
enum aiTextureType;

namespace gam703::engine::graphic
{
	class Model
	{

	public:
		Model(const std::filesystem::path& path);
		void draw(const Shader& shader) const;

	private:
		void loadModel(const std::filesystem::path& path);
		void processNode(const aiNode* node, const aiScene* scene);
		Mesh processMesh(const aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> loadMaterialTextures(const aiMaterial* mat, aiTextureType type);

		std::vector<Texture> m_texturesLoaded;
		std::vector<Mesh> m_meshes;
		std::filesystem::path m_directory;
	};

}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_HPP
