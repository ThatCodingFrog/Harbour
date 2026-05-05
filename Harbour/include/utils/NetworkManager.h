#pragma once
#include <memory>

namespace HarbourUtils
{
    class DownloadManager;
    class FileManager;

    class NetworkManager
    {
    public:
        NetworkManager(FileManager *fileManager);
        ~NetworkManager();

    private:
        std::unique_ptr<DownloadManager> m_downloadManager;
        FileManager *m_fileManager = nullptr;

        void checkForManifestUpdate();
        void checkForSelfUpdate();
    };

}