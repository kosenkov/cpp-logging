#ifndef COMMON_H 
#define COMMON_H

#include <chrono>
#include <cstdarg>
#include <vector>


namespace Logging {

    namespace Common
    {
        using logging_time = std::chrono::time_point<std::chrono::system_clock>;

        inline std::string args_format(const char* const format, ...)
        {
            va_list vaArgs;
            va_start(vaArgs, format);

            va_list vaArgsCopy;
            va_copy(vaArgsCopy, vaArgs);

            //calc size for log message with args...
            const auto length = std::vsnprintf(nullptr, 0, format, vaArgsCopy);
            va_end(vaArgsCopy);

            if(length < 0)
            {
                va_end(vaArgs);
                throw "args_format: error formatting message string";
            }

            std::vector<char> complete_buf(length + 1);// "+1" for terminate symbol '\0'
            std::vsnprintf(complete_buf.data(), complete_buf.size(), format, vaArgs);
            va_end(vaArgs);

            return std::string(complete_buf.data(), length);
        }

        namespace TimeUtil
        {
            inline std::tm localtime( std::time_t t )
            {
                #if defined(_WIN32)
                    return *std::localtime(&t);
                #else // POSIX
                    std::tm temp;
                    return *::localtime_r( &t, &temp );
                #endif // _MSC_VER
            }

            inline std::string date_to_string(const logging_time& time_point, const char* date_format)//%d-%m-%Y or other
            {
                using namespace std::chrono;

                // convert to std::time_t in order to convert to std::tm (broken time)
                auto timer = system_clock::to_time_t(time_point);

                // convert to broken time
                auto bt = TimeUtil::localtime(timer);

                //formatting time string
                char buffer[80];
                strftime(buffer, sizeof(buffer), date_format, &bt);

                return std::string(buffer);
            }

            inline std::string time_to_string(const logging_time& time_point, const char* date_format)//%H-%M-%S or other
            {
                return date_to_string(time_point, date_format);
            }
        }
    }
}




#endif