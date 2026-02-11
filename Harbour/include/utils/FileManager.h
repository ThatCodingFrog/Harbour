#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "GameCard.h"

namespace HarbourUtils {

	//VersionInfo struct concept comes from ChatGPT
	struct VersionInfo {
		int major;
		int minor;
		int patch;
	};

	class FileManager {
	public:
		void createNewDirectory(std::string dir = "test");
		void writeFile(std::string file, std::string data);
		std::string readFile(std::string file);

		//Update related functions
		nlohmann::json readJSON(std::string file);
		std::string makeCURLRequest(const char* url);

		void constructLibraryFromJSON(std::vector<Harbour::GameCard>& output, std::string lib);

		void checkLatestVersions();

		//Running executables
		void startGame(std::string file);

	private:
		//Check latest releases from Github
		nlohmann::json checkShipVersion();
		nlohmann::json check2ShipVersion();
		nlohmann::json checkStarShipVersion();

		//This function is also from ChatGPT (although under a different, more appropriate name)
		VersionInfo parseVersionString(const std::string& versionStr);
		bool versionOutdated(const VersionInfo& installed, const VersionInfo& latest);

	};
}