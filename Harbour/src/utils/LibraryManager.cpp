#include "utils/LibraryManager.h"
#include "utils/FileManager.h"

#include <iostream>
#include <filesystem>

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
    if (libJSON.empty() || !libJSON.contains("ports"))
    {
        std::cout << "No library entries found at " << path << ", returning empty library." << std::endl;
        return library;
    }

    recurseJSON(libJSON["ports"], library);

    return library;
}

Harbour::GameCard HarbourUtils::LibraryManager::makeEntry(nlohmann::json entry)
{
    if (entry.contains("name") && entry.contains("version"))
    {
        Harbour::GameCard card;
        std::string name = entry["name"].get<std::string>();
        std::string version = entry["version"].get<std::string>();

        card.setName(name);
        card.setVersion(version);
        card.setThumbnailImg("assets/GameCard/UnknownTitle.png");
        return card;
    }

    return Harbour::GameCard();
}

void HarbourUtils::LibraryManager::recurseJSON(nlohmann::json object, std::vector<Harbour::GameCard> &library)
{
    if (!object.is_object() && !object.is_array())
        return;

    for (auto &entry : object.items())
    {
        if (entry.key() == "baseURL" || entry.key() == "harbour")
            continue;

        if (entry.value().is_object() || entry.value().is_array())
            this->recurseJSON(entry.value(), library);
        else if (entry.value().is_string())
        {
            if (entry.value().get<std::string>().find(".json") != std::string::npos)
            {
                std::filesystem::path resolvedPath = std::filesystem::path("cache/ports") / entry.value().get<std::string>();

                nlohmann::json details = m_fileManager->loadConfigFile(resolvedPath);

                Harbour::GameCard card = this->makeEntry(details);
                library.push_back(card);
            }
        }
    }
}
