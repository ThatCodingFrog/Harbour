#include "utils/DownloadManager.h"
#include <cpr/cpr.h>
#include <cpr/cprtypes.h>

#include <filesystem>
#include "utils/FileManager.h"

namespace fs = std::filesystem;
using namespace cpr;

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
    fs::path outPath = "/downloads/" / fs::path(task.name) / ".zip";
    fs::path realPath = HarbourUtils::resolvePath(outPath);

    m_downloadFuture = cpr::DownloadAsync(
        realPath,
        cpr::Url{task.url},
        cpr::ProgressCallback([this](cpr_pf_arg_t dlTotal, cpr_pf_arg_t dlNow, cpr_pf_arg_t, cpr_pf_arg_t, intptr_t) -> bool
                              { m_currentDownloadProgress.store(static_cast<double>(dlNow) / dlTotal); return true; }));
}
