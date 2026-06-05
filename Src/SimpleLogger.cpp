#include "SimpleLogger.h"
#include "SimpleLogItem.h"
#include "File.h"
#include <cstdarg>

namespace Logger
{
    SimpleLogger::~SimpleLogger()
    {
    }

    SimpleLogger::SimpleLogger() :
        mMaxFileSize(sDefaultMaxFileSize),
        mLogLevel(sDefaultLevel)
    {
    }

    SimpleLogger::SimpleLogger( const size_t maxFileSize, const LogLevel level ) :
        mMaxFileSize(maxFileSize),
        mLogLevel(level)
    {
    }

    const LogLevel& SimpleLogger::GetLogLevel() const
    {
        return mLogLevel;
    }

    void SimpleLogger::SetLogLevel( const LogLevel& level )
    {
        mLogLevel = level;
    }

    LoggerOperationResult SimpleLogger::Log( const LogLevel level, const SimpleLogItem& item )
    {
        LoggerOperationResult res = LoggerOperationResult::Success;

        if( level <= mLogLevel )
        {
            if( FileSystemUtils::File::Exists( item.GetFilePath().c_str() ) == false )
            {
                FileSystemUtils::File::Create( item.GetFilePath().c_str(), W_OK | R_OK );
            }

            int len = FileSystemUtils::File::Append( item.GetFilePath().c_str(), item.Str() );
    
            if( len > 0 )
            {
                res = LoggerOperationResult::Success;
            }
            else
            {
                printf("SimpleLogger::Log %s", FileSystemUtils::File::GetErrorStr().c_str() );
                res = LoggerOperationResult::Failure;
            }
        }
        else
        {
            res = LoggerOperationResult::Success;
        }

        return res;
    }

    LoggerOperationResult SimpleLogger::Log( const LogLevel level, const std::string& filePath, const char* msg, ... )
    {
        LoggerOperationResult res = LoggerOperationResult::Success;

        if( level <= mLogLevel )
        {
            if( FileSystemUtils::File::Exists( filePath.c_str() ) == false )
            {
                FileSystemUtils::File::Create( filePath.c_str(), W_OK | R_OK );
            }

            va_list args;
            va_start(args, msg);
            ::Logger::SimpleLogItem item = ::Logger::SimpleLogItem(filePath.c_str(), level, msg, &args);
            va_end(args);
            
            int len = FileSystemUtils::File::Append( filePath.c_str(), item.Str() );
            
            if( len > 0 )
            {
                res = LoggerOperationResult::Success;
            }
            else
            {
                printf("SimpleLogger::Log %s", FileSystemUtils::File::GetErrorStr().c_str() );
                res = LoggerOperationResult::Failure;
            }
        }
        else
        {
            res = LoggerOperationResult::Success;
        }

        return res;
    }
} // namespace Logger
