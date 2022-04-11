#ifndef TXTWRITER_H 
#define TXTWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include "../include/src/IWriter.h"

template<class Formatter>
class TxtWriter : public Logging::IWriter
{
public:
    TxtWriter(const std::string &file)
        : m_outfile(file)
    {
        
    }

    ~TxtWriter()
    {
        m_outfile.close();
    }

    void Write(const Logging::Record &record) override
    {
        if(!m_outfile.is_open())
        {
            throw "TxtWriter::Write: file is not open";
        }

        m_outfile << m_formatter.apply(record);
    }

private:
    std::ofstream m_outfile;
    Formatter m_formatter;
};


#endif