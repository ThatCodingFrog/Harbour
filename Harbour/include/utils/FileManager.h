#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "GameCard.h"
#include <filesystem>

namespace fs = std::filesystem;

namespace HarbourUtils
{
	const fs::path resolvePath(const fs::path &path);
	const fs::path resolvePath(const std::string &path);

	class FileManager
	{
	public:
		FileManager();
		~FileManager();

		FileManager *get();

		void saveConfigFile(const nlohmann::json &config, const fs::path &path);
		nlohmann::json loadConfigFile(const fs::path &path);

		bool fileExists(const fs::path &path);
		bool directoryExists(const fs::path &path, bool createIfMissing);

		bool unzipArchive(const fs::path &path, const fs::path &destination);
	};
}