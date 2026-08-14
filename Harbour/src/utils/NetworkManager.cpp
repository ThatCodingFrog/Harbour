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

    this->checkForSelfUpdate();
}

HarbourUtils::NetworkManager::~NetworkManager()
{
}

HarbourUtils::NetworkManager *HarbourUtils::NetworkManager::get()
{
    return this;
}

void HarbourUtils::NetworkManager::checkForManifestUpdate()
{
    nlohmann::json etags = m_fileManager->loadConfigFile("cache/etags.json");

    cpr::Header headers = {
        {"Expect", ""}};

    if (etags.contains("manifest"))
    {
        headers["If-None-Match"] = etags["manifest"].get<std::string>();
    }

    cpr::Url url = "https://raw.githubusercontent.com/ThatCodingFrog/harbour-manifest/main/manifest-bundled.json";
    cpr::Response r = cpr::Get(url, headers);

    if (r.status_code == 304)
    {
        std::cout << "Using cached manifest" << std::endl;
        return;
    }
    else if (r.status_code != 200)
    {
        std::cerr << "Failed to get manifest: " << r.status_code << std::endl;
        return;
    }

    std::string manifestETag = r.header["ETag"];
    if (!manifestETag.empty())
    {
        etags["manifest"] = manifestETag;
        m_fileManager->saveConfigFile(etags, "cache/etags.json");
    }

    nlohmann::json manifest = nlohmann::json::parse(r.text);

    m_fileManager->saveConfigFile(manifest, "cache/manifest.json");
}

void HarbourUtils::NetworkManager::checkForSelfUpdate()
{
}
