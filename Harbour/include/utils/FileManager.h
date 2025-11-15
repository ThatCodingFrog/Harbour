#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>


namespace HarbourUtils {
	class FileManager {
	public:
		void createNewDirectory(std::string dir = "test");
		void writeFile(std::string file, std::string data);
		std::string readFile(std::string file);

		//nlohmann::json readJSON(std::string file);
	};
}