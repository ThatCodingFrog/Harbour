#include "utils/FileManager.h"
#include <fstream>
#include <iostream>
#include <exception>

namespace fs = std::filesystem;

HarbourUtils::FileManager::FileManager()
{
}

HarbourUtils::FileManager::~FileManager()
{
}

HarbourUtils::FileManager *HarbourUtils::FileManager::get()
{
    return this;
}

void HarbourUtils::FileManager::saveConfigFile(const nlohmann::json &config, const std::string &path)
{
    fs::path filePath(path);
    if (!filePath.parent_path().empty() && !fs::exists(filePath.parent_path()))
    {
        fs::create_directories(filePath.parent_path());
    }

    std::ofstream stream(path, std::ios::out | std::ios::trunc);
    if (stream.is_open())
    {
        stream << config.dump(4);
        stream.close();
    }
    else
    {
        std::cerr << "Failed to open file for writing: " << path << std::endl;
    }
}

nlohmann::json HarbourUtils::FileManager::loadConfigFile(const std::filesystem::path &path)
{
    try
    {
        std::ifstream stream(path);
        if (stream.is_open())
        {
            nlohmann::json config;
            stream >> config;
            stream.close();
            return config;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error while reading config file " << path << ": " << e.what() << std::endl;
    }

    return {};
}
bool HarbourUtils::FileManager::unzipArchive(const std::filesystem::path &path, const std::string &destination)
{
    // Placeholder implementation
    return true;
}