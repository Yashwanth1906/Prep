#include "adapter.cpp"

int main() {
    LegacyPrinter* oldPrinter = new LegacyPrinter();
    Printer* printer = new PrinterAdapter(oldPrinter);
    printer->printDocument("Hello from the Adapter Pattern!");
    delete printer;
    delete oldPrinter;
    return 0;
}