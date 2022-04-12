#ifndef RECORD_H 
#define RECORD_H

#include <chrono>
#include <string>
#include "Common.h"


namespace Logging 
{
    enum class Level
    {
        Error = 0,
        Warning,
        Info,
        Debug,
        Undefined
    };

    class Record
    {
    public: 
            explicit Record(
                const Level level,
                const size_t line_number,
                const std::string& caller_func,
                const std::string& message
            )
                : m_level(level)
                , m_line_number(line_number)
                , m_caller_func(caller_func)
                , m_message(message)
            {}

            Level level() const {
                return m_level;
            }

            const Common::logging_time& time() const {
                return m_time;
            }

            size_t line() const {
                return m_line_number;
            }

            const std::string& caller_func() const {
                return m_caller_func;
            }

            const std::string& message() const {
                return m_message;
            }

        private:
            Level m_level = Level::Undefined;
            Common::logging_time m_time = std::chrono::system_clock::now();
            size_t m_line_number = 0;
            std::string m_caller_func = "";
            std::string m_message = "";
    };
}

#endif