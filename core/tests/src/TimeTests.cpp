#include <gtest/gtest.h>
#include <core/Time.hpp>

TEST(TimeTests, SetTime)
{
	const double expected = 20;
	gam703::engine::core::Time time(expected);

	EXPECT_EQ(expected, time.getTime());
}

TEST(TimeTests, UpdateDeltaTime)
{
	const double initialTime = 20;
	gam703::engine::core::Time time(initialTime);

	ASSERT_EQ(initialTime, time.getTime());

	const double timeStep = 5;
	const double newTime = initialTime + timeStep;

	time.processTime(newTime);

	EXPECT_EQ(newTime, time.getTime());
	EXPECT_EQ(timeStep, time.getDeltaTime());
}

int main(int argc, char** argv)
{
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
