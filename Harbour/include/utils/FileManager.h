#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include "GameCard.h"

namespace HarbourUtils {
	class FileManager {
	public:
		void createNewDirectory(std::string dir = "test");
		void writeFile(std::string file, std::string data);
		std::string readFile(std::string file);

		//Updating related functions
		nlohmann::json readJSON(std::string file);
		std::string makeCURLRequest(const char* url);

		void constructLibraryFromJSON(std::vector<Harbour::GameCard>& output, std::string lib);

		void checkLatestVersions();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
		//Running executables
		void startGame(std::string file);
>>>>>>> Stashed changes
=======
		//Running executables
		void startGame(std::string file);
>>>>>>> Stashed changes

	private:
		nlohmann::json checkShipVersion();
		nlohmann::json check2ShipVersion();
		nlohmann::json checkStarShipVersion();
	};
}