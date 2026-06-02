#include "utils/LibraryManager.h"
#include "utils/FileManager.h"

#include "nlohmann/json.hpp"
#include <iostream>

HarbourUtils::LibraryManager::LibraryManager(HarbourUtils::FileManager *fileManager)
{
    m_fileManager = fileManager;
}

HarbourUtils::LibraryManager::~LibraryManager()
{
}

std::vector<Harbour::GameCard> HarbourUtils::LibraryManager::constructLibraryFromJSON(std::string path)
{
    std::vector<Harbour::GameCard> library;

    nlohmann::json libJSON = m_fileManager->loadConfigFile(path);
    if (libJSON.empty())
    {
        std::cout << "No library entries found at " << path << ", returning empty library." << std::endl;
        return library;
    }

    return library;
}