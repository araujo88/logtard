
#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include "logger.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace logtard
{
    class ConsoleLogger : public Logger
    {
    public:
        virtual void log(const std::string &message, logtard::LogLevel level, const char *file, int line) override;
    };
}

#endif
