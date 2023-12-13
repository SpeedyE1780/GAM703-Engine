#include <engine/utility/File.hpp>

#include <gtest/gtest.h>

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
