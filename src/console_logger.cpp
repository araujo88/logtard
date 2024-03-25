#include "../include/console_logger.hpp"

using namespace logtard;

std::string ConsoleLogger::logLevelToString(LogLevel level)
{
    switch (level)
    {
    case LogLevel::DEBUG:
        return "DEBUG";
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    case LogLevel::CRITICAL:
        return "CRITICAL";
    default:
        return "UNKNOWN";
    }
}

void ConsoleLogger::log(const std::string &message, tpt::LogLevel level, const char *file, int line)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time);

    // Use logLevelToString to convert the LogLevel to a string
    std::string levelStr = logLevelToString(level);

    std::cout << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] ";
    std::cout << "[" << levelStr << "] ";

    if (file)
    {
        std::cout << "[" << file << ":" << line << "] ";
    }

    std::cout << message << std::endl;
}

void ConsoleLogger::debug(const std::string &message)
{
    log(message, LogLevel::DEBUG);
}

void ConsoleLogger::info(const std::string &message)
{
    log(message, LogLevel::INFO);
}

void ConsoleLogger::warning(const std::string &message)
{
    log(message, LogLevel::WARNING);
}

void ConsoleLogger::error(const std::string &message)
{
    log(message, LogLevel::ERROR);
}

void ConsoleLogger::critical(const std::string &message)
{
    log(message, LogLevel::CRITICAL);
}
