#pragma once
#include <iostream>
#include <mutex>
using namespace std;
class Logger {
    static int counter;
    static Logger* loggerInstance;
    static mutex mtx;
    Logger();
public:
    static Logger* getLogger();
    void log(string msg);
};