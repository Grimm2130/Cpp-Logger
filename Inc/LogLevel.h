#if !defined(__LOG_LEVEL_H__)
#define __LOG_LEVEL_H__

#include "CppTemplates/Templates.h"
#include <string>

namespace Logger
{
    enum class LogLevel
    {
        Fatal,
        Error,
        Debug,
        Info,
        Trace
    };

    /// @brief Log Level Helper functions
    class LogLevelUtils
    {
    public:
        inline static const std::string Str( const LogLevel level )
        {
            switch( level )
            {
                case LogLevel::Fatal:   return "Fatal";
                case LogLevel::Error:   return "Error";
                case LogLevel::Debug:   return "Debug";
                case LogLevel::Info:    return "Info";
                case LogLevel::Trace:   return "Trace";
                default:                return "__None__";
            }
        }
    private:
        CLASS_IS_STATIC_ONLY(LogLevelUtils)
    };
} // namespace Logger


#endif // __LOG_LEVEL_H__
