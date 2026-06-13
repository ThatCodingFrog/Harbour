#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "GameCard.h"
#include <filesystem>

namespace HarbourUtils
{
	class FileManager
	{
	public:
		FileManager();
		~FileManager();

		FileManager *get();

		void saveConfigFile(const nlohmann::json &config, const std::string &path);
		nlohmann::json loadConfigFile(const std::filesystem::path &path);

		bool unzipArchive(const std::filesystem::path &path, const std::string &destination);
	};
}