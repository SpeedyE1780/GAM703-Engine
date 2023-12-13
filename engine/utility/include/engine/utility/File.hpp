#ifndef GAM703_ENGINE_UTILITY_FILE_HPP
#define GAM703_ENGINE_UTILITY_FILE_HPP

#include <engine/utility/Config.hpp>

#include <filesystem>
#include <string>

namespace gam703::engine::utility
{
	ENGINE_UTILITY_API std::string readFile(const std::filesystem::path& filePath);
	ENGINE_UTILITY_API void writeFile(const std::string& content, const std::filesystem::path& filePath);
} // namespace gam703::engine::utility

#endif // GAM703_ENGINE_UTILITY_FILE_HPP
