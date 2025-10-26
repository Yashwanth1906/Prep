#include "adaptee.cpp"

class PrinterAdapter : public Printer {
private:
    LegacyPrinter* legacyPrinter;
public:
    PrinterAdapter(LegacyPrinter* lp) : legacyPrinter(lp) {}
    
    void printDocument(const std::string& content) override {
        legacyPrinter->printText(content);
    }
};
