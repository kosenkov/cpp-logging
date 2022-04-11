
#include "../include/Logging.h"
#include "TxtWriter.h"
#include "TxtFormatter.h"

int main()
{
    TxtWriter<TxtFormatter> writer("LoggerTest.txt");
    Logging::Logger::init(&writer);

    logf_e("Error message with arg: Num=%d, Str=%s",     1, "Error message");
    logf_w("Warning message with arg : Num=%d, Str=%s",  2, "Warning message");
    logf_i("Info message with arg : Num=%d, Str=%s",     3, "Info message");
    logf_d("Debug message with arg : Num=%d, Str=%s",    4, "Debug message");


    log_e("Error message without args.");
    log_w("Warning message without args.");
    log_i("Info message without args.");
    log_d("Debug message without args.");


    return 0;
}
