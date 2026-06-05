#if !defined(__LOG_ITEM_H__)
#define __LOG_ITEM_H__

#include "ILogItem.h"
#include "LogLevel.h"
#include <cstdint>

namespace Logger
{
    class SimpleLogItem : public ILogItem
    {
    public:
        SimpleLogItem(const char*filePath, const LogLevel level, const char* msg, ... );
        SimpleLogItem(const char*filePath, const LogLevel level, const char* msg, va_list* args );
        ~SimpleLogItem() override;
        std::string Str() const override;
        const std::string& GetFilePath() const;
    private:
        constexpr static size_t StrBufferSize = 0x1000;
        constexpr static size_t LogBufferSize = 0x400;
        LogLevel mLevel;
        uint64_t mTimeStamp;
        std::string mFilePath;
        char mLog[LogBufferSize];
    };
} // namespace Logger


#endif // __LOG_ITEM_H__
