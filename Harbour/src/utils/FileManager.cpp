#include "utils/FileManager.h"
#include <vector>

void HarbourUtils::FileManager::createNewDirectory(std::string dir)
{
	std::filesystem::create_directory(dir);
}

void HarbourUtils::FileManager::writeFile(std::string file, std::string data)
{
	std::ofstream stream(file);
	stream << data << std::endl;
	stream.close();
}

std::string HarbourUtils::FileManager::readFile(std::string file)
{
	std::vector<std::string> contents = {};

	std::ifstream stream(file);

	std::string result = "";
	for (int i = 0; i < contents.size(); i++) {
		result += contents.at(i);
	}
	return result;

}
