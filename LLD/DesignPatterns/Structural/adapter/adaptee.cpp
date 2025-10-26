#include "target.cpp"
#include "../builder/product.cpp"

class LegacyPrinter {
public:
    void printText(const std::string& text) {
        std::cout << "Legacy Printer printing: " << text << std::endl;
    }
};