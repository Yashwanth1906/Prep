#include <bits/stdc++.h>
#include <mutex>
#include <memory>
#include <thread>
using namespace std;

// ================= Product =================
class Product {
private:
    int id, price, quantity;
    string name;
public:
    Product(int id, int price, int quantity, string name)
        : id(id), price(price), quantity(quantity), name(name) {}

    int getId() const { return id; }
    int getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    string getName() const { return name; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }
};

// ================= Payment Strategy =================
class PaymentStrategy {
public:
    virtual bool pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CashPayment : public PaymentStrategy {
public:
    bool pay(int amount) override {
        cout << "Cash Payment Done Successfully: " << amount << endl;
        return true;
    }
};

class UPIPayment : public PaymentStrategy {
public:
    bool pay(int amount) override {
        cout << "UPI Payment Done Successfully: " << amount << endl;
        return true;
    }
};

class CardPayment : public PaymentStrategy {
public:
    bool pay(int amount) override {
        cout << "Card Payment Done Successfully: " << amount << endl;
        return true;
    }
};

// ================= Vending Machine =================
class VendingMachine {
private:
    int id;
    vector<shared_ptr<Product>> products;
    mutex mtx;
public:
    VendingMachine(int id, vector<shared_ptr<Product>> products)
        : id(id), products(products) {}

    bool buy(int productId, int quantity, int inputPrice, PaymentStrategy* payment) {
        lock_guard<mutex> lock(mtx);

        shared_ptr<Product> productWanted = nullptr;
        for (auto& product : products) {
            if (product->getId() == productId) {
                productWanted = product;
                break;
            }
        }

        if (!productWanted) {
            cout << "Product not found!" << endl;
            return false;
        }

        if (productWanted->getQuantity() < quantity) {
            cout << "Not enough Quantity" << endl;
            return false;
        }

        int totalPrice = quantity * productWanted->getPrice();
        if (inputPrice < totalPrice) {
            cout << "Not enough money to buy the item" << endl;
            return false;
        }

        // Process payment via strategy
        if (!payment->pay(totalPrice)) {
            cout << "Payment failed!" << endl;
            return false;
        }

        // Reduce stock
        productWanted->setQuantity(productWanted->getQuantity() - quantity);
        cout << "Product bought successfully. Balance: " 
             << inputPrice - totalPrice << endl;
        return true;
    }
};

// ================= Thread Function =================
void buyAProduct(shared_ptr<VendingMachine> vm) {
    CashPayment cash;
    vm->buy(1, 6, 600, &cash);
}

// ================= Main =================
int main() {
    auto redBull = make_shared<Product>(1, 100, 10, "Red Bull");
    auto sting   = make_shared<Product>(2, 50, 10, "Sting");

    auto vm = make_shared<VendingMachine>(1, vector<shared_ptr<Product>>{redBull, sting});

    thread user1(buyAProduct, vm);
    thread user2(buyAProduct, vm);

    user1.join();
    user2.join();

    return 0;
}