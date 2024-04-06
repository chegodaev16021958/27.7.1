#include "Logger.h"

void Logger::writeLine(const std::string& text)
{
    shared_mutex.lock();
    std::fstream iofile("log.txt", std::ios::out | std::ios::app);
    iofile << text;
    shared_mutex.unlock();
    return;
}

void Logger::readLine(std::string& text, int numberOfLine)
{
    shared_mutex.lock_shared();
    std::fstream iofile("log.txt", std::ios::in);
    for (int i = 0; i < numberOfLine; ++i)
    {
        std::getline(iofile, text);
    }
    shared_mutex.unlock_shared();
    return;
}