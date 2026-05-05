#include "utils/NetworkManager.h"
#include "utils/DownloadManager.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include "utils/FileManager.h"

HarbourUtils::NetworkManager::NetworkManager(FileManager *fileManager)
{
    m_downloadManager = std::make_unique<DownloadManager>();
    m_fileManager = fileManager;
    this->checkForManifestUpdate();
}

HarbourUtils::NetworkManager::~NetworkManager()
{
}

void HarbourUtils::NetworkManager::checkForManifestUpdate()
{
    nlohmann::json etags = m_fileManager->loadConfigFile("cache/etags.json");

    cpr::Header headers = {{}};
    cpr::Url url = "https://raw.githubusercontent.com/ThatCodingFrog/harbour-manifest/main/manifest.json";
    cpr::Response r = cpr::Get(url);

    std::cout << r.status_code << "\n"
              << r.header["Content-Type"] << std::endl;

    std::cout << r.text << std::endl;

    nlohmann::json manifest = nlohmann::json::parse(r.text);

    std::cout << manifest.dump(4) << std::endl;

    m_fileManager->saveConfigFile(manifest, "cache/manifest.json");
}

void HarbourUtils::NetworkManager::checkForSelfUpdate()
{
}
