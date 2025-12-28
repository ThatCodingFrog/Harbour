#pragma once
#include <string>
#include <deque>

namespace HarbourUtils {
	struct DownloadTask {
		int id; //location in download queue
		std::string url; //URL to download, from nlohmann::json
		float progress; //0.0 - 1.0 for ImGui
	};

	class DownloadManager {
	public:
		DownloadManager();
		~DownloadManager();

		void addDownload(const std::string& url);
		void updateDownloads();
	
	private:
		std::deque<DownloadTask> m_downloadQueue;
	};
}