#pragma once
#include <string>
#include <deque>
#include <vector>
#include <memory>
#include <atomic>

namespace HarbourUtils
{
	struct HttpResponse
	{
		int code;
		std::string body;
		std::string etag;
		bool not_modified; // True if we got a 304
	};

	struct DownloadTask
	{
		std::string url;
		std::string name;

		std::string destinationPath; // Where the ZIP goes

		// Thread-safe progress tracking
		std::atomic<double> progress{0.0};
		std::atomic<bool> isComplete{false};
		std::atomic<bool> failed{false};

		HttpResponse response;
	};

	class DownloadManager
	{
	public:
		DownloadManager();
		~DownloadManager();

		void addDownload(const DownloadTask &task);
		void updateDownloads();

	public:
		std::vector<std::shared_ptr<DownloadTask>> getActiveDownloads() const
		{
			return m_activeDownloads;
		}

	private:
		std::deque<DownloadTask> m_downloadQueue;
		std::vector<std::shared_ptr<DownloadTask>> m_activeDownloads;
	};
}