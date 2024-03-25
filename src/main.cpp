#include "../include/console_logger.hpp"

int main()
{
    logtard::ConsoleLogger logger;
    LOG_INFO(logger, "This is an informational message.");
    LOG_DEBUG(logger, "This is a debug message.");
    LOG_ERROR(logger, "This is an error message.");
    LOG_WARNING(logger, "This is a warning message.");
    LOG_CRITICAL(logger, "This is a critical message.");

    return 0;
}
