#include <gtest/gtest.h>
#include <core/Time.hpp>

TEST(TimeTests, SetTime)
{
	const double expected = 20;

	gam703::engine::core::Time time(expected);

	EXPECT_EQ(expected, time.getTime());
}

int main(int argc, char** argv)
{
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
