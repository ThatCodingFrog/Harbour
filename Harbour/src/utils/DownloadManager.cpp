#include "utils/DownloadManager.h"

HarbourUtils::DownloadManager::DownloadManager()
{
}

HarbourUtils::DownloadManager::~DownloadManager()
{
}

void HarbourUtils::DownloadManager::addDownload(const std::string& url)
{
	DownloadTask task = {};
	task.url = url;
	task.progress = 0.0f;
	task.id = m_downloadQueue.size();

	m_downloadQueue.push_back(task);
}

void HarbourUtils::DownloadManager::updateDownloads()
{
	for (const auto &download : m_downloadQueue) {

	}
}
