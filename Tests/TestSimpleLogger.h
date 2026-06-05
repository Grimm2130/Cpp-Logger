#if !defined(__TEST_SIMPLE_LOGGER_H__)
#define __TEST_SIMPLE_LOGGER_H__

#include "CppTemplates/Templates.h"
#include "CppTemplates/ITest.h"
#include "SimpleLogItem.h"
#include "SimpleLogger.h"

namespace Logger
{    
    namespace Tests
    {
        class SimpleLogger : public ::Tests::ITest
        {
            bool RunTests() override
            {
                bool res = false;
                logger = new ::Logger::SimpleLogger;

                printf("SimpleLogger::Running tests....\n");

                if( TestLogItem() )
                {
                    if(TestLog() )
                    {
                        printf("SimpleLogger::All test run successfully\n");
                    }
                }

                delete logger;

                return res;
            }
        private:
            static bool TestLogItem()
            {
                bool res;
                logItem = new ::Logger::SimpleLogItem( filePath, level, "Hello from Chima");

                if( logger->Log(level, (*logItem)) == LoggerOperationResult::Success )
                {
                    res = true;
                }
                else
                {
                    printf("SimpleLogger::TestLogItem()\n");
                    res = false;
                }

                delete logItem;

                return res;
            }

            static bool TestLog()
            {
                if( logger->Log(level, filePath, "Hello from Chima - %s", "Log") == LoggerOperationResult::Success )
                {
                    return true;
                }
                else
                {
                    printf("SimpleLogger::TestLog()\n");
                    return false;
                }
            }

            static ::Logger::SimpleLogger *logger;
            static ::Logger::SimpleLogItem *logItem;
            static constexpr char* filePath = (char*)"/home/ubuntu/Projects/Logger/Tests/TestFiles/LogFile.txt";
            static constexpr ::Logger::LogLevel level = LogLevel::Debug;
        };

        ::Logger::SimpleLogItem *SimpleLogger::logItem = nullptr;
        Logger::SimpleLogger* Logger::Tests::SimpleLogger::logger = nullptr;

    } // namespace Tests
} // namespace SimpleLogger


#endif // __TEST_SIMPLE_LOGGER_H__
