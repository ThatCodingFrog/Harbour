#include "utils/DownloadManager.h"
#include <cpr/cpr.h>
#include <filesystem>

namespace fs = std::filesystem;

HarbourUtils::DownloadManager::DownloadManager()
{
}

HarbourUtils::DownloadManager::~DownloadManager()
{
}

void HarbourUtils::DownloadManager::addDownload(std::string url, std::string name = "Harbour Ports Download")
{
    std::lock_guard<std::mutex> lock(m_downloadLock);
    DownloadTask task = {url, name};
    m_downloads.push_back(task);
    if (m_downloads.size() == 1)
        this->startDownload(task);
}

double HarbourUtils::DownloadManager::getCurrentDownloadProgress()
{
    return m_currentDownloadProgress;
}

void HarbourUtils::DownloadManager::startDownload(HarbourUtils::DownloadTask &task)
{
    fs::path outPath = "/downloads/" + task.name + ".zip";
    // auto response = cpr::DownloadAsync();
}
