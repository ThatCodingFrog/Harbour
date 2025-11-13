#include "utils/FileManager.h"

void HarbourUtils::FileManager::createNewDirectory(std::string dir)
{
	std::filesystem::create_directory(dir);
	std::ofstream dirCreate("test/file.txt");
	dirCreate << "Testing directory building";
	dirCreate.close();
}