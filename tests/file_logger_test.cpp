#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "../include/file_logger.hpp"

namespace logtard_tests
{

    class FileLoggerTest : public ::testing::Test
    {
    protected:
        std::string tempFilePath = "temp_log.txt";

        virtual void SetUp()
        {
            // Ensure the file is removed if it already exists
            std::remove(tempFilePath.c_str());
        }

        virtual void TearDown()
        {
            // Clean up the file after each test
            std::remove(tempFilePath.c_str());
        }

        // Helper function to read file content
        std::string readFileContent(const std::string &filePath)
        {
            std::ifstream file(filePath);
            return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        }
    };

    TEST_F(FileLoggerTest, LogsMessageToFile)
    {
        // Setup
        logtard::FileLogger logger(tempFilePath);

        // Action
        logger.log("Test message", logtard::LogLevel::INFO, __FILE__, __LINE__);

        // Verification
        std::string fileContent = readFileContent(tempFilePath);
        EXPECT_NE(fileContent.find("Test message"), std::string::npos) << "The log message was not found in the file.";

        // Optional: more detailed checks can be added to verify the date, time, log level, file name, and line number format.
    }

} // namespace logtard_tests
