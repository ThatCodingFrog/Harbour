#pragma once
#include <string>

namespace HarbourUtils {
	struct Download {
		int id; //location in download queue
		std::string url; //URL to download, from nlohmann::json
		float progress; //0.0 - 1.0 for ImGui
	};

	class DownloadManager {
	public:
		DownloadManager();
		~DownloadManager();

		void updateDownloads();
	};
}