#include "logger.hpp"

int Logger::counter = 0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;

Logger* Logger::getLogger() {
    if(loggerInstance == nullptr) {
        mtx.lock();
        if(loggerInstance == nullptr) {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}

Logger::Logger() {
    counter++;
    cout<<"No of Instances : "<<counter<<endl;
}

void Logger::log(string msg) {
    cout<<msg<<endl;
}