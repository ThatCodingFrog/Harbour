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
    this->directoryExists(destination, true); // Ensure directory for extracting exists

    struct archive *a;

    return true;
}

/**
 * Placeholder code
 #include <archive.h>
#include <archive_entry.h>
#include <iostream>
#include <string>

bool extractArchive(const std::string& archivePath, const std::string& destinationDir) {
    struct archive* a = archive_read_new();
    struct archive* ext = archive_write_disk_new();

    // Enable auto-detection for all supported formats and filters (.zip, .tar.gz, .7z, etc.)
    archive_read_support_format_all(a);
    archive_read_support_filter_all(a);

    // Set write options to preserve structure, permissions, and timestamps
    int flags = ARCHIVE_EXTRACT_TIME
              | ARCHIVE_EXTRACT_PERM
              | ARCHIVE_EXTRACT_ACL
              | ARCHIVE_EXTRACT_FFLAGS;

    archive_write_disk_set_options(ext, flags);
    archive_write_disk_set_standard_lookup(ext);

    // Open the input archive file
    if (archive_read_open_filename(a, archivePath.c_str(), 10240) != ARCHIVE_OK) {
        std::cerr << "Failed to open archive: " << archive_read_error_string(a) << std::endl;
        archive_read_free(a);
        archive_write_free(ext);
        return false;
    }

    struct archive_entry* entry;
    int r;

    // Iterate through every file/directory in the archive
    while (true) {
        r = archive_read_next_header(a, &entry);
        if (r == ARCHIVE_EOF) {
            break; // Finished reading archive
        }
        if (r < ARCHIVE_OK) {
            std::cerr << "Header warning/error: " << archive_read_error_string(a) << std::endl;
        }
        if (r < ARCHIVE_WARN) {
            break; // Fatal error
        }

        // Prepend output destination path if needed
        std::string currentPath = archive_entry_pathname(entry);
        std::string fullPath = destinationDir.empty() ? currentPath : destinationDir + "/" + currentPath;
        archive_entry_set_pathname(entry, fullPath.c_str());

        // Write header (creates directory hierarchy automatically)
        r = archive_write_header(ext, entry);
        if (r < ARCHIVE_OK) {
            std::cerr << "Write header error: " << archive_write_error_string(ext) << std::endl;
        } else if (archive_entry_size(entry) > 0) {
            // Copy data blocks from input archive to target file on disk
            const void* buff;
            size_t size;
            int64_t offset;

            while (true) {
                r = archive_read_data_block(a, &buff, &size, &offset);
                if (r == ARCHIVE_EOF) break;
                if (r < ARCHIVE_OK) {
                    std::cerr << "Read data block error: " << archive_read_error_string(a) << std::endl;
                    break;
                }

                r = archive_write_data_block(ext, buff, size, offset);
                if (r < ARCHIVE_OK) {
                    std::cerr << "Write data block error: " << archive_write_error_string(ext) << std::endl;
                    break;
                }
            }
        }
        archive_write_finish_entry(ext);
    }

    // Clean up handles
    archive_read_close(a);
    archive_read_free(a);
    archive_write_close(ext);
    archive_write_free(ext);

    return r == ARCHIVE_EOF;
}
 */