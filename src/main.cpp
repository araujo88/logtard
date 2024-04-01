#include "../include/console_logger.hpp"
#include "../include/file_logger.hpp"

int main()
{
    logtard::ConsoleLogger logger1;
    logtard::FileLogger logger2;

    LOG_INFO(logger1, "This is an informational message.");
    LOG_DEBUG(logger1, "This is a debug message.");
    LOG_ERROR(logger1, "This is an error message.");
    LOG_WARNING(logger1, "This is a warning message.");
    LOG_CRITICAL(logger1, "This is a critical message.");

    LOG_INFO(logger2, "This is an informational message.");
    LOG_DEBUG(logger2, "This is a debug message.");
    LOG_ERROR(logger2, "This is an error message.");
    LOG_WARNING(logger2, "This is a warning message.");
    LOG_CRITICAL(logger2, "This is a critical message.");

    return 0;
}
