
#ifndef FILE_LOGGER_H_
#define FILE_LOGGER_H_

#include "logger.hpp"

namespace logtard
{
    class FileLogger : public Logger
    {
    private:
        std::ofstream logFile;

    public:
        FileLogger(const std::string &filePath);
        ~FileLogger();
        virtual void log(const std::string &message, logtard::LogLevel level, const char *file, int line) override;
    };
}

#endif
