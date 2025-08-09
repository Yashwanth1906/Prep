#include <iostream>
using namespace std;

class Printer {
public:
    virtual void printDocument(const std::string& content) = 0;
    virtual ~Printer() {}
};