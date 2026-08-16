#pragma once
#include <string>

#include <mutex>
#include <atomic>
#include <deque>

namespace HarbourUtils
{
	struct DownloadTask
	{
		std::string url;
		std::string name;
	};

	class DownloadManager
	{
	public:
		DownloadManager();
		~DownloadManager();

		void addDownload(std::string url, std::string name); // determine params later
		double getCurrentDownloadProgress();

	private:
		void startDownload(DownloadTask &task);

		std::mutex m_downloadLock;
		std::deque<DownloadTask> m_downloads;
		std::atomic<double> m_currentDownloadProgress = 0.0;
	};
}