#ifndef IWRITER_H 
#define IWRITER_H

#include "Record.h"


namespace Logging 
{
    class IWriter 
    {
    public:
        virtual ~IWriter() {}
        virtual void Write(const Record &record) = 0;
    };
}

#endif