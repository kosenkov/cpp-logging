#ifndef LOGGING_H 
#define LOGGING_H

#include <stdexcept>
#include "src/IWriter.h"


//log with formatting
#define logf_i(format, ...) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Info,	__LINE__,	__FUNCTION__, Logging::Common::args_format(format, __VA_ARGS__)));}
#define logf_e(format, ...) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Error,	__LINE__,	__FUNCTION__, Logging::Common::args_format(format, __VA_ARGS__)));}
#define logf_w(format, ...) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Warning,	__LINE__,	__FUNCTION__, Logging::Common::args_format(format, __VA_ARGS__)));}
#define logf_d(format, ...) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Debug,	__LINE__,	__FUNCTION__, Logging::Common::args_format(format, __VA_ARGS__)));}

//log without formatting
#define log_i(message) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Info,	    __LINE__,	__FUNCTION__, message));}
#define log_e(message) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Error,	__LINE__,	__FUNCTION__, message));}
#define log_w(message) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Warning,	__LINE__,	__FUNCTION__, message));}
#define log_d(message) {Logging::Logger::instance().write(Logging::Record(Logging::Level::Debug,	__LINE__,	__FUNCTION__, message));}

namespace Logging
{
    class Logger : public IWriter
    {
    public:    
        static void init(IWriter *writer = nullptr)
        {
            m_writer = writer;
        }

        static Logger& instance()
        {
            static Logger instance;
            return instance;
        }

        void write(const Record &record) override 
        {
            if(m_writer != nullptr)
                m_writer->write(record);
        }

    private:
        Logger() {};
        ~Logger() {};
        Logger(const Logger&) = delete;
        Logger(Logger&&) noexcept = delete;
        Logger& operator=(Logger&) = delete;
        Logger& operator=(Logger&&) noexcept = delete;

        static IWriter *m_writer;
    };

    Logger::IWriter *Logger::m_writer = nullptr;    
}

#endif