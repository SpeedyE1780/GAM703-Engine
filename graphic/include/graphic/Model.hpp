#ifndef GAM703_ENGINE_GRAPHIC_MODEL_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_HPP

#include <graphic/Config.hpp>
#include <graphic/Mesh.hpp>
#include <graphic/Shader.fwd.hpp>

#include <core-interfaces/IResourceManager.hpp>

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
	class GRAPHIC_API Model
	{

	public:
		Model(const std::filesystem::path& path, core_interface::IResourceManager* resourceManager);
		void draw(const Shader& shader) const;

	private:
		void loadModel(const std::filesystem::path& path);
		void processNode(const aiNode* node, const aiScene* scene);
		Mesh processMesh(const aiMesh* mesh, const aiScene* scene);
		void loadMaterialTextures(std::vector<const core_interface::ITexture*>& textures, const aiMaterial* mat, aiTextureType type) const;

		std::vector<Mesh> m_meshes;
		std::filesystem::path m_directory;
		core_interface::IResourceManager* m_resourceManager;
	};

}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_HPP
