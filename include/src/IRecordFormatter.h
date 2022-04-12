#ifndef IRECORDFORMATTER_H 
#define IRECORDFORMATTER_H

#include <string>
#include "Record.h"


namespace Logging 
{
    class IRecordFormatter
    {
    public:
        virtual ~IRecordFormatter() {}
        virtual std::string apply(const Record& record) = 0;
    };
}

#endif