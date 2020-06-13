#ifndef PONG_LOGGER_HPP
#define PONG_LOGGER_HPP

#include <iostream>

class Logger
{
public:
    template<typename... Args>
    static void logError(const Args&... args)
    {
        (std::cerr << ... << args) << "\n";
    }

    template<typename... Args>
    static void logMessage(const Args&... args)
    {
        (std::cout << ... << args) << "\n";
    }
};


#endif //PONG_LOGGER_HPP
