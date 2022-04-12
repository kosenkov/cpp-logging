# Logging

[![Typing SVG](https://readme-typing-svg.herokuapp.com?color=03B61F&vCenter=true&lines=Very+simple+logging+library+implementation!)](https://git.io/typing-svg)

:warning: The library is currently under development!

:bangbang: The library is temporarily not thread-safe!

##### Now you can already:
:heavy_check_mark: Create your own class "writer" for writing according to your preferences (see example);

:heavy_check_mark: Create your own "formatter" for data output;

:heavy_check_mark: Carticipate in the development of the library;

:heavy_check_mark: Contact me for constructive criticism and suggestions for improvement;


### How to use (see example):

```C++
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
```
