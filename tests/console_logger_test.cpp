#include <gtest/gtest.h>
#include "console_logger.hpp"
#include <sstream>

namespace logtard_tests
{

    class ConsoleLoggerTest : public ::testing::Test
    {
    protected:
        std::stringstream buffer;
        std::streambuf *sbuf;
        logtard::ConsoleLogger logger;

        void SetUp() override
        {
            // Redirect std::cout to buffer
            sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());
        }

        void TearDown() override
        {
            // Reset std::cout
            std::cout.rdbuf(sbuf);
        }
    };

    TEST_F(ConsoleLoggerTest, LogsDebugMessage)
    {
        logger.log("Test message", logtard::LogLevel::DEBUG, "test_file.cpp", 42);

        // Expect that the output contains certain substrings
        EXPECT_NE(buffer.str().find("[DEBUG]"), std::string::npos);
        EXPECT_NE(buffer.str().find("Test message"), std::string::npos);
        EXPECT_NE(buffer.str().find("test_file.cpp:42"), std::string::npos);
    }

    TEST_F(ConsoleLoggerTest, LogsInfoMessage)
    {
        logger.log("Another test message", logtard::LogLevel::INFO, nullptr, 0);

        // Expect that the output contains certain substrings
        EXPECT_NE(buffer.str().find("[INFO]"), std::string::npos);
        EXPECT_NE(buffer.str().find("Another test message"), std::string::npos);
        // File and line information should not be present
        EXPECT_EQ(buffer.str().find(":0"), std::string::npos);
    }

} // namespace logtard_tests
