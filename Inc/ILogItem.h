#if !defined(__ILOG_ITEM_H__)
#define __ILOG_ITEM_H__

#include <string>

namespace Logger
{
    class ILogItem
    {
    public:
        ILogItem() = default;
        virtual ~ILogItem() = default;
        virtual std::string Str() const = 0;
    private:
    };

}

#endif // __ILOG_ITEM_H__
