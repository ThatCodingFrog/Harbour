#include <vector>
#include "GameCard.h"
#include <string>

namespace HarbourUtils
{
    class FileManager;

    class LibraryManager
    {
    public:
        LibraryManager(FileManager *fileManager);
        ~LibraryManager();

        std::vector<Harbour::GameCard> constructLibraryFromJSON(std::string path);

    private:
        FileManager *m_fileManager = nullptr;
    };
}