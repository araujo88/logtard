#include "../include/console_logger.hpp"

#define LOG(logger, level, message) (logger).log(message, level, __FILE__, __LINE__)
#define LOG_DEBUG(logger, message) LOG(logger, tpt::LogLevel::DEBUG, message)
#define LOG_INFO(logger, message) LOG(logger, tpt::LogLevel::INFO, message)
#define LOG_WARNING(logger, message) LOG(logger, tpt::LogLevel::WARNING, message)
#define LOG_ERROR(logger, message) LOG(logger, tpt::LogLevel::ERROR, message)
#define LOG_CRITICAL(logger, message) LOG(logger, tpt::LogLevel::CRITICAL, message)

int main() {
    tpt::ConsoleLogger logger;
    LOG_INFO(logger, "This is an informational message.");
    return 0;
}
