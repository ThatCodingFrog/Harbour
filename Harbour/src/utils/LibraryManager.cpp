#include "utils/LibraryManager.h"
#include "utils/FileManager.h"

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

    std::cout << libJSON.dump(4) << std::endl;

    for (const auto &entry : libJSON)
    {
        std::cout << "Entry:" << entry.dump(4) << std::endl;
    }

    return library;
}

Harbour::GameCard HarbourUtils::LibraryManager::makeEntry(nlohmann::json entry)
{
    if (entry.contains("name") && entry.contains("version"))
    {
        return Harbour::GameCard(entry["name"].get<std::string>(), entry["version"].get<std::string>());
    }

    return Harbour::GameCard();
}
