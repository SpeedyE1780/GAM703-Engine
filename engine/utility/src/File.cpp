#include <engine/utility/File.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

namespace gam703::engine::utility
{
	std::string readFile(const std::filesystem::path& filePath)
	{
		if (std::filesystem::exists(filePath) && !std::filesystem::is_empty(filePath))
		{
			try
			{
				std::ifstream file(filePath, std::ios::in);

				if (file.is_open())
				{
					file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
					std::stringstream fileContent{};
					fileContent << file.rdbuf();
					file.close();
					return fileContent.str();
				}
			}
			catch (std::ifstream::failure& e)
			{
				std::cout << "ERROR: " << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "FILE NOT FOUND" << std::endl;
		}

		return "";
	}

	void writeFile(const std::string& content, const std::filesystem::path& filePath)
	{
		try
		{
			std::ofstream file(filePath, std::ios::out);

			if (file.is_open())
			{
				file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
				file << content;
				file.close();
			}
		}
		catch (std::ifstream::failure& e)
		{
			std::cout << "ERROR: " << e.what() << std::endl;
		}
	}
}
