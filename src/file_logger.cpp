#include "../include/file_logger.hpp"

namespace logtard
{
    FileLogger::FileLogger(const std::string &path)
    {
        logFile.open(path, std::ios::out | std::ios::app); // Open for writing in append mode
        if (!logFile.is_open())
        {
            std::cerr << "Failed to open log file: " << path << std::endl;
        }
    }

    FileLogger::~FileLogger()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    void FileLogger::log(const std::string &message, logtard::LogLevel level, const char *file, int line)
    {
        if (!logFile.is_open())
        {
            std::cerr << "Attempt to log to an unopened file." << std::endl;
            return;
        }

        // Get current time
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm = *std::localtime(&now_time);

        // Convert log level to string
        std::string levelStr = logLevelToString(level);

        // Format and write the log message
        logFile << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] "
                << "[" << levelStr << "] ";

        if (file)
        {
            logFile << "[" << file << ":" << line << "] ";
        }

        logFile << message << std::endl;
    }
}
