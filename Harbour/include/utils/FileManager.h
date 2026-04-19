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

		bool unzipArchive(const std::string &path, const std::string &destination);
	};
}