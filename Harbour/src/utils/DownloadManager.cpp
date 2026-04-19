#include "utils/DownloadManager.h"

HarbourUtils::DownloadManager::DownloadManager()
{
}

HarbourUtils::DownloadManager::~DownloadManager()
{
}

void HarbourUtils::DownloadManager::addDownload(const DownloadTask &task)
{
	m_downloadQueue.push_back(task);
}

void HarbourUtils::DownloadManager::updateDownloads()
{
}
