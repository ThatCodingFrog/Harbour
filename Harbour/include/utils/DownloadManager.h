#pragma once
#include <string>
#include <vector>

namespace HarbourUtils
{
	struct DownloadTask
	{
		std::string url;
		std::string name;
		float progress = 0.0f;
	};

	class DownloadManager
	{
	public:
		DownloadManager();
		~DownloadManager();

		void addDownload(); // determine params later
		void updateDownloads();

	private:
		std::vector<DownloadTask> m_downloads;
	};
}