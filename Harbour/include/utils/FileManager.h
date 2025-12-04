#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

namespace HarbourUtils {
	class FileManager {
	public:
		void createNewDirectory(std::string dir = "test");
		void writeFile(std::string file, std::string data);
		std::string readFile(std::string file);

		nlohmann::json readJSON(std::string file);
		std::string makeCURLRequest(const char* url);

		void checkLatestVersions();

	private:
		nlohmann::json checkShipVersion();
		nlohmann::json check2ShipVersion();
		nlohmann::json checkStarShipVersion();
	};
}