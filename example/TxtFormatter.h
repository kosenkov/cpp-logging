#ifndef TXTFORMATTER_H 
#define TXTFORMATTER_H

#include <string>
#include <sstream>
#include "../include/src/IRecordFormatter.h"
#include "../include/src/Common.h"


class TxtFormatter : public Logging::IRecordFormatter
{
public:
    std::string apply(const Logging::Record& record) override 
    {
        std::string date = Logging::Common::TimeUtil::date_to_string(record.time(), "%Y-%m-%d");
        std::string time = Logging::Common::TimeUtil::time_to_string(record.time(), "%H:%M:%S");
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(record.time().time_since_epoch()) % 1000;

        std::string type = "";
        switch (record.level())
        {
        case Logging::Level::Error:
            type = "[ERROR]";
            break;    
        
        case Logging::Level::Warning:
            type = "[WARN]";
            break;

        case Logging::Level::Info:
            type = "[INFO]";
            break;

        case Logging::Level::Debug:
            type = "[DEBUG]";
            break;



        default:
            type = "[???]";
            break;
        }

        std::stringstream ss;
        ss << date << "\t";
        ss << time << ":" << milliseconds.count() << "\t";
        ss << type << "\t";
        ss << record.caller_func() << "\t";
        ss << "[Line " << record.line() << "]" << "\t";
        ss << record.message();
        ss << "\n";

        return ss.str();
    }
};

#endif