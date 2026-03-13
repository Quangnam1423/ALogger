#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <config.h>
#include <stdio.h>
#include <string>
#include <filesystem>
#include <fstream>

namespace ALogger
{
    /*
     * @brief FileManager class responsible for handling file operations related to logging.
    */
    class ALOGGER_API FileManager
    {
    public: // constructors and destructors
        /// @brief  Constructor for FileManager.
        /// @param logDirectory 
        explicit FileManager(const std::string& logDirectory);

        /// @brief Destructor for FileManager.
        ~FileManager();
    public: // public methods
        /// @brief 
        /// @return 
        bool Initialize();

        /// @brief  
        /// @param logFileName 
        /// @return 
        std::string GetLogFilePath(const std::string& logFileName) const;

        /// @brief  
        /// @return 
        std::string GetDailyLogFilePath() const;

        /// @brief 
        /// @param filename 
        /// @param content 
        /// @return
        bool WriteToFile(const std::string& filename, const std::string& content);

        /// @brief  
        /// @param filename 
        /// @return 
        std::string ReadFromFile(const std::string& filename);

    private: // private methods
        /// @brief Create the log directory if it doesn't exist.
        /// @return true if the directory was created or already exists, false otherwise.
        bool CreateLogDirectory();

        /// @brief  Get the current date as a string in the format "YYYY-MM-DD".
        /// @return 
        std::string GetCurrentDateString() const;

    private: // properties
        std::string logDirectory_;
    };
}

#endif // FILE_MANAGER_H