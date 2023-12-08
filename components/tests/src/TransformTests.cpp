#include <gtest/gtest.h>
#include <components/Transform.hpp>

namespace gam703::engine::components::tests
{

	TEST(TransformTests, TransformConstructor)
	{
		Transform transform{};

		glm::vec3 position = glm::vec3(0, 0, 0);
		glm::vec3 scale = glm::vec3(1, 1, 1);
		glm::quat rotation = glm::quat(glm::vec3(0, 0, 0));
		EXPECT_EQ(position, transform.getPosition());
		EXPECT_EQ(scale, transform.getScale());
		EXPECT_EQ(rotation, transform.getRotation());
	}
} //gam703::engine::components::tests
