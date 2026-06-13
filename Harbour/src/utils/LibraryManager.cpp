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

    recurseJSON(libJSON);

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

void HarbourUtils::LibraryManager::recurseJSON(nlohmann::json object)
{
    for (const auto &entry : object)
    {
        if (entry.is_object())
        {
            this->recurseJSON(entry);
        }
        else
        {
            auto val = entry.get<std::string>();
            if (val.find(".json") != std::string::npos)
            {
                // Skip the harbour.json entry, as it is not a game
                if (val.find("harbour") != std::string::npos)
                    continue;

                std::cout << "Found entry: " << val << std::endl;

                // Code to resolve the path to actual JSON file
                nlohmann::json detailedJSON = m_fileManager->loadConfigFile("cache/ports/" + val);

                this->makeEntry(detailedJSON);
            }
        }
    }
}
