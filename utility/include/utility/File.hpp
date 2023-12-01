#ifndef GAM703_ENGINE_UTILITY_FILE_HPP
#define GAM703_ENGINE_UTILITY_FILE_HPP

#include <filesystem>
#include <string>

namespace gam703::engine::utility
{
	std::string readFile(const std::filesystem::path& filePath);
	void writeFile(const std::string& content, const std::filesystem::path& filePath);
} // namespace gam703::engine::utility

#endif // GAM703_ENGINE_UTILITY_FILE_HPP
