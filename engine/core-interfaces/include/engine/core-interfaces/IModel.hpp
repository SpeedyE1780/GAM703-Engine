#ifndef GAM703_ENGINE_CORE_INTERFACES_IMODEL_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IMODEL_HPP

#include <engine/core-interfaces/IMaterial.hpp>

namespace gam703::engine::core_interface
{
	class IModel
	{
	public:
		~IModel() = default;
		virtual void draw(const IMaterial& material) const = 0;

	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IMODEL_HPP