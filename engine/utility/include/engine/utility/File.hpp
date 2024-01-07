#ifndef GAM703_ENGINE_UTILITY_FILE_HPP
#define GAM703_ENGINE_UTILITY_FILE_HPP

#include <engine/utility/Config.hpp>

#include <filesystem>
#include <string>

namespace gam703::engine::utility
{
	/// @brief Reads file and return content
	/// @param filePath The file path where the file is located
	/// @return The file content
	ENGINE_UTILITY_API std::string readFile(const std::filesystem::path& filePath);

	/// @brief Write content to file
	/// @param content The content to write in file
	/// @param filePath File location
	ENGINE_UTILITY_API void writeFile(const std::string& content, const std::filesystem::path& filePath);
} // namespace gam703::engine::utility

#endif // GAM703_ENGINE_UTILITY_FILE_HPP
