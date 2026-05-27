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

void HarbourUtils::NetworkManager::checkForManifestUpdate()
{
    nlohmann::json etags = m_fileManager->loadConfigFile("cache/etags.json");

    cpr::Header headers = {
        {"Expect", ""}};

    if (etags.contains("manifest"))
    {
        headers["If-None-Match"] = etags["manifest"].get<std::string>();
    }

    cpr::Url url = "https://raw.githubusercontent.com/ThatCodingFrog/harbour-manifest/main/manifest.json";
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
    nlohmann::json etags = m_fileManager->loadConfigFile("cache/etags.json");
    nlohmann::json manifest = m_fileManager->loadConfigFile("cache/manifest.json");

    cpr::Header headers = {
        {"Expect", ""}};

    if (etags.contains("harbour"))
    {
        headers["If-None-Match"] = etags["harbour"].get<std::string>();
    }

    // Validate manifest is loaded and has required keys
    if (manifest.is_null() || manifest.empty() || !manifest.contains("baseURL"))
    {
        std::cerr << "Manifest is invalid or missing required keys" << std::endl;
        return;
    }

    cpr::Url url = manifest["baseURL"].get<std::string>() + manifest["ports"]["harbour"].get<std::string>();
    cpr::Response r = cpr::Get(url, headers);

    if (r.status_code == 304)
    {
        std::cout << "No updates available" << std::endl;
        return;
    }
    else if (r.status_code != 200)
    {
        std::cerr << "Error while checking for self update: " << r.status_code << std::endl;
        return;
    }

    std::string harbourETag = r.header["ETag"];
    if (!harbourETag.empty())
    {
        etags["harbour"] = harbourETag;
        m_fileManager->saveConfigFile(etags, "cache/etags.json");
    }

    nlohmann::json harbourInfo = nlohmann::json::parse(r.text);

    m_fileManager->saveConfigFile(harbourInfo, "cache/harbour.json");
}
