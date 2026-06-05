#include "SimpleLogger.h"
#include "SimpleLogItem.h"
#include "ExternalModules/FileSystemUtils/Inc/File.h"

namespace Logger
{
    SimpleLogger::SimpleLogger() :
        mMaxFileSize(sDefaultMaxFileSize)
    {
    }

    SimpleLogger::SimpleLogger( const size_t maxFileSize ) :
        mMaxFileSize(maxFileSize)
    {
    }

    LoggerOperationResult SimpleLogger::Log( const SimpleLogItem& item )
    {
        int len = FileSystemUtils::File::Write( item.GetFilePath().c_str(), item.Str() );

        if( len > 0 )
        {
            return LoggerOperationResult::Success;
        }
        else
        {
            printf("SimpleLogger::Log %s", FileSystemUtils::File::GetErrorStr().c_str() );
            return LoggerOperationResult::Failure;
        }
    }

    LoggerOperationResult SimpleLogger::Log( const std::string& filePath, const char* msg, ... )
    {
        
        if( FileSystemUtils::File::Exists( filePath.c_str() ) == false )
        {
            FileSystemUtils::File::Create( filePath.c_str(), W_OK | R_OK );
        }
     
        int len = FileSystemUtils::File::Write( filePath.c_str(), msg );

        if( len > 0 )
        {
            return LoggerOperationResult::Success;
        }
        else
        {
            printf("SimpleLogger::Log %s", FileSystemUtils::File::GetErrorStr().c_str() );
            return LoggerOperationResult::Failure;
        }
    }

    
} // namespace Logger
