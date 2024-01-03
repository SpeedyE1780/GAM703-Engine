#include <engine/graphic/Model.hpp>

namespace gam703::engine::graphic
{
	Model::Model(const std::vector<Mesh>& meshes) : m_meshes(meshes)
	{
	}

	void Model::draw(const core_interface::Material& material) const
	{
		std::for_each(begin(m_meshes), end(m_meshes), [&material](const Mesh& mesh) { mesh.draw(material); });
	}
}
