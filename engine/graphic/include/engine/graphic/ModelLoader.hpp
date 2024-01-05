#ifndef GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP

#include <engine/core/ResourceManager.fwd.hpp>
#include <engine/graphic/Texture.hpp>

#include <engine/graphic/Config.hpp>
#include <engine/graphic/Model.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	class ENGINE_GRAPHIC_API ModelLoader
	{
	public:
		ModelLoader(core::ResourceManager* resourceManager);

		Model* loadModel(const std::filesystem::path& path);
		void processNode(std::vector<Mesh>& meshes, const aiNode* node, const aiScene* scene);
		Mesh processMesh(const aiMesh* mesh, const aiScene* scene);
		void loadMaterialTextures(std::vector<const Texture*>& textures, const aiMaterial* mat, aiTextureType type);

	private:
		core::ResourceManager* m_resourceManager;
		std::filesystem::path m_currentDirectory;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP
