#include "utils/FileManager.h"
#include <fstream>
#include <iostream>
#include <exception>
#include <archive.h>

HarbourUtils::FileManager::FileManager()
{
    this->directoryExists("cache/downloads", true); // Creates cache/downloads/ folder for downloaded archives to be put in
    this->directoryExists("games", true);
}

HarbourUtils::FileManager::~FileManager()
{
}

HarbourUtils::FileManager *HarbourUtils::FileManager::get()
{
    return this;
}

void HarbourUtils::FileManager::saveConfigFile(const nlohmann::json &config, const fs::path &path)
{
    if (!path.parent_path().empty() && !fs::exists(path.parent_path()))
    {
        fs::create_directories(path.parent_path());
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

nlohmann::json HarbourUtils::FileManager::loadConfigFile(const fs::path &path)
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

bool HarbourUtils::FileManager::fileExists(const fs::path &path)
{
    if (fs::exists(path) && fs::is_regular_file(path))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool HarbourUtils::FileManager::directoryExists(const fs::path &path, bool createIfMissing)
{
    if (fs::exists(path) && fs::is_directory(path))
    {
        return true;
    }
    else
    {
        if (createIfMissing)
        {
            fs::create_directories(path);
        }
        return false;
    }
}

bool HarbourUtils::FileManager::unzipArchive(const fs::path &path, const fs::path &destination)
{
    // Placeholder implementation
    // Use libarchive
    return true;
}