#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

// ---------------- Logger Class ----------------
class Logger {
private:
    static Logger* loggerInstance;
    static mutex mtx;
    static int counter;

    // Private constructor
    Logger() {
        counter++;
        cout << "No of Instances: " << counter << endl;
    }

public:

    // Get singleton instance
    static Logger* getLogger() {
        if (loggerInstance == nullptr) {
            lock_guard<mutex> lock(mtx); // thread-safe lock
            if (loggerInstance == nullptr) {
                loggerInstance = new Logger();
            }
        }
        return loggerInstance;
    }

    void log(const string& msg) {
        cout << msg << endl;
    }
};

// Static member initialization
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;
int Logger::counter = 0;

// ---------------- Test Code ----------------
void user1Logs() {
    Logger* logger1 = Logger::getLogger();
    logger1->log("Logger 1");
}

void user2Logs() {
    Logger* logger2 = Logger::getLogger();
    logger2->log("Logger 2");
}

int main() {
    thread t1(user1Logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();

    return 0;
}
