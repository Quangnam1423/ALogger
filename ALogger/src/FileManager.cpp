#include <FileManager.h>

namespace ALogger
{
    FileManager::FileManager(const std::string& logDirectory)
        : logDirectory_(logDirectory)
    {
    }

    FileManager::~FileManager()
    {
    }

    bool FileManager::Initialize()
    {
        return CreateLogDirectory();
    }

    std::string FileManager::GetLogFilePath(const std::string& logFileName) const
    {
        return logDirectory_ + "/" + logFileName;
    }

    std::string FileManager::GetDailyLogFilePath() const
    {
        std::string dateStr = GetCurrentDateString();
        return GetLogFilePath("log_" + dateStr + ".txt");
    }

    bool FileManager::WriteToFile(const std::string& filename, const std::string& content)
    {
        std::ofstream outFile(filename, std::ios::app);
        if (!outFile.is_open())
        {
            return false;
        }
        outFile << content << std::endl;
        outFile.close();
        return true;
    }

    std::string FileManager::ReadFromFile(const std::string& filename)
    {
        std::ifstream inFile(filename);
        if (!inFile.is_open())
        {
            return "";
        }
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();
        return content;
    }

    bool FileManager::CreateLogDirectory()
    {
        try
        {
            if (!std::filesystem::exists(logDirectory_))
            {
                return std::filesystem::create_directories(logDirectory_);
            }
            return true; // Directory already exists
        }
        catch (const std::filesystem::filesystem_error& e)
        {
            // Handle error (e.g., log it)
            return false;
        }
    }

    std::string FileManager::GetCurrentDateString() const
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&in_time_t));
        
        return std::string(buffer);
    }
}