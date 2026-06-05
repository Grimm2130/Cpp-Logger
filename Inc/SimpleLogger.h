#if !defined(__SIMPLE_LOGGER_H__)
#define __SIMPLE_LOGGER_H__

#include "LogLevel.h"
#include <cstdio>
#include <string>

namespace Logger
{
    class SimpleLogItem;

    enum class LoggerOperationResult
    {
        Success,
        Failure
    };

    class SimpleLogger
    {
    public:
        SimpleLogger();
        SimpleLogger( const size_t maxFileSize, const LogLevel level );
        const LogLevel& GetLogLevel()const ;
        void SetLogLevel( const LogLevel& level );
        LoggerOperationResult Log( const LogLevel level, const SimpleLogItem& );
        LoggerOperationResult Log( const LogLevel level, const std::string& filePath, const char* msg, ... );
        // LoggerOperationResult LogAsync( const SimpleLogItem& );
        // LoggerOperationResult LogAsync( const std::string& filePath, const char* msg, ... );
        ~SimpleLogger();
    private:
        size_t mMaxFileSize;        // bytes
        LogLevel mLogLevel;         // Log level
        static constexpr size_t sDefaultMaxFileSize = 0x100000;
        static constexpr LogLevel sDefaultLevel = LogLevel::Debug;
    };
} // namespace SimpleLogger


#endif // __SIMPLE_LOGGER_H__
