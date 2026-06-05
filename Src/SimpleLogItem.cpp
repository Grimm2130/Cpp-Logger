#include "SimpleLogItem.h"
#include "LogLevel.h"

#include <cstdarg>

namespace Logger
{
    SimpleLogItem::SimpleLogItem(const char*filePath, const LogLevel level, const char* msg, ... ):
        mFilePath(filePath),
        mLevel(level)
    {
        if( msg )
        {
            va_list args;
            va_start( args, msg );
            int len = vsnprintf( mLog, LogBufferSize, msg, args);
            va_end( args );
        }
        else
        {
            mLog[0] = '\0';
        }
    }

    SimpleLogItem::~SimpleLogItem()
    {

    }

    std::string SimpleLogItem::Str() const
    {
        char buffer[StrBufferSize];

        int len = snprintf( buffer, StrBufferSize, "[%lu]::[%s] %s\n", 
            mTimeStamp, 
            LogLevelUtils::Str(mLevel).c_str(),
            mLog
        );

        return std::string(buffer);
    }

    const std::string& SimpleLogItem::GetFilePath() const
    {
        return mFilePath;
    }
} // namespace Logger

