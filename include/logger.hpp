#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <mutex>

namespace logtard
{

    // Define the LogLevel enum to specify the severity of the log messages.
    enum class LogLevel
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };

    // Logger base class with virtual methods for logging messages at different severity levels.
    class Logger
    {
    protected:
        std::mutex logMutex;
        std::string logLevelToString(LogLevel level);

    public:
        virtual ~Logger() {}
        virtual void log(const std::string &message, LogLevel level, const char *file, int line) = 0;
#define LOG(logger, level, message) (logger).log(message, level, __FILE__, __LINE__)
#define LOG_DEBUG(logger, message) LOG(logger, logtard::LogLevel::DEBUG, message)
#define LOG_INFO(logger, message) LOG(logger, logtard::LogLevel::INFO, message)
#define LOG_WARNING(logger, message) LOG(logger, logtard::LogLevel::WARNING, message)
#define LOG_ERROR(logger, message) LOG(logger, logtard::LogLevel::ERROR, message)
#define LOG_CRITICAL(logger, message) LOG(logger, logtard::LogLevel::CRITICAL, message)
    };

} // namespace logtard

#endif // LOGGER_H_
