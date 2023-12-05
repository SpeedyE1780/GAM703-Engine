#include <gtest/gtest.h>

TEST(TimeTests, UpdateDeltaTime)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv)
{
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
