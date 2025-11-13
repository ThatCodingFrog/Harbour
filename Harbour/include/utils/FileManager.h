#pragma once
#include <filesystem>
#include <fstream>
#include <string>

namespace HarbourUtils {
	class FileManager {
	public:
		void createNewDirectory(std::string dir = "test");
	};
}