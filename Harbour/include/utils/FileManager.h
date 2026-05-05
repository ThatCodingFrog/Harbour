#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "GameCard.h"

namespace HarbourUtils
{
	class FileManager
	{
	public:
		FileManager();
		~FileManager();

		FileManager *get();

		void saveConfigFile(const nlohmann::json &config, const std::string &path);
		nlohmann::json loadConfigFile(const std::string &path);

		bool unzipArchive(const std::string &path, const std::string &destination);
	};
}