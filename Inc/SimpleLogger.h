#if !defined(__SIMPLE_LOGGER_H__)
#define __SIMPLE_LOGGER_H__

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
        SimpleLogger( const size_t maxFileSize );
        LoggerOperationResult Log( const SimpleLogItem& );
        LoggerOperationResult Log( const std::string& filePath, const char* msg, ... );
        // LoggerOperationResult LogAsync( const SimpleLogItem& );
        // LoggerOperationResult LogAsync( const std::string& filePath, const char* msg, ... );
        ~SimpleLogger();
    private:
        size_t mMaxFileSize;        // bytes
        static constexpr size_t sDefaultMaxFileSize = 0x100000;
    };
} // namespace SimpleLogger


#endif // __SIMPLE_LOGGER_H__
