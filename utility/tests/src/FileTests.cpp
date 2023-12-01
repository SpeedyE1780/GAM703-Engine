#include <gtest/gtest.h>
#include <utility/File.hpp>

TEST(FileTests, ReadTest)
{
	const std::string expected = "THIS IS A READ TEST!\n";
	const std::string fileContent = gam703::engine::utility::readFile("ReadTest.txt");
	EXPECT_EQ(expected, fileContent);
}

TEST(FileTests, WriteTest)
{
	const std::string fileContent = "THIS IS A WRITE TEST!\n";
	const std::filesystem::path path("WriteTest.txt");
	gam703::engine::utility::writeFile(fileContent, path);
	EXPECT_EQ(fileContent, gam703::engine::utility::readFile(path));
}

int main(int argc, char** argv)
{
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
