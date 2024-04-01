#include <gtest/gtest.h>
#include <fstream>
#include <thread>
#include <vector>
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

    TEST_F(FileLoggerTest, LogsMessagesFromMultipleThreads)
    {
        const int numberOfThreads = 10;
        logtard::FileLogger logger(tempFilePath);

        // Lambda function for logging
        auto logAction = [&logger](int threadId)
        {
            for (int j = 0; j < 100; ++j)
            { // Each thread logs 100 times
                logger.log("Message " + std::to_string(j) + " from thread " + std::to_string(threadId), logtard::LogLevel::INFO, __FILE__, __LINE__);
            }
        };

        // Create and start threads
        std::vector<std::thread> threads;
        for (int i = 0; i < numberOfThreads; ++i)
        {
            threads.emplace_back(logAction, i);
        }

        // Join threads
        for (auto &thread : threads)
        {
            thread.join();
        }

        // Now read the file and verify all messages are logged
        std::ifstream file(tempFilePath);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        bool allMessagesLogged = true;
        for (int i = 0; i < numberOfThreads; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                std::string expectedMessage = "Message " + std::to_string(j) + " from thread " + std::to_string(i);
                if (content.find(expectedMessage) == std::string::npos)
                {
                    allMessagesLogged = false;
                    std::cerr << "Missing: " << expectedMessage << std::endl;
                }
            }
        }
        EXPECT_TRUE(allMessagesLogged) << "Not all messages were logged correctly.";
    }

} // namespace logtard_tests
