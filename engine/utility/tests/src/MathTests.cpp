#include <engine/utility/Math.hpp>

#include <gtest/gtest.h>

namespace gam703::engine::utility::tests
{
	TEST(MathTests, MoveTowardsLessThanMaxDistance)
	{
		glm::vec3 current{ 0.0f, 0.0f, 0.0f };
		glm::vec3 target{ 0.0f, 0.0f, 1.0f };
		glm::vec3 result = moveTowards(current, target, 2.0f);

		EXPECT_EQ(target, result);
	}

	TEST(MathTests, MoveTowardsMoreThanMaxDistance)
	{
		glm::vec3 current{ 0.0f, 0.0f, 0.0f };
		glm::vec3 target{ 0.0f, 0.0f, 2.0f };
		glm::vec3 intermediate{ 0.0f, 0.0f, 1.0f };
		glm::vec3 result = moveTowards(current, target, 1.0f);

		EXPECT_EQ(intermediate, result);

		result = moveTowards(result, target, 1.0f);

		EXPECT_EQ(target, result);
	}
}
