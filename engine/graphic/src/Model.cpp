#include <engine/graphic/Model.hpp>

namespace gam703::engine::graphic
{
	Model::Model(const std::vector<Mesh>& meshes) : m_meshes(meshes)
	{
	}

	void Model::draw(const core_interface::IShader& shader) const
	{
		std::for_each(begin(m_meshes), end(m_meshes), [&shader](const Mesh& mesh) { mesh.draw(shader); });
	}
}
