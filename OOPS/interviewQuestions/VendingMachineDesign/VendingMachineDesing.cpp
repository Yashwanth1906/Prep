// Product -> id, name, price, quantity. Getter , setter as they will be private variables. reduceQuantity().
// Vending Machine -> id, vector<Product>. buy(productId, quantity, inputPrice). -> bool. 
#include <bits/stdc++.h>
using namespace std;

class Product {
private:
    int id, price,quantity;
    string name;
public:
    Product(int id, int price, int quantity, string name) : id(id), price(price), quantity(quantity), name(name){}
    int getId() {
        return this->id;
    }
    int getPrice() {
        return this->price;
    }
    int getQuantity() {
        return this->quantity;
    }
    void setQuantity(int newQuantity) {
        this->quantity = newQuantity;
    }
};

class VendingMachine {
private:
    int id;
    vector<Product*> products;
public:
    VendingMachine(int id, vector<Product*> products) {
        this->id = id;
        this->products = products;
    }
    bool buy(int productId, int quantity, int inputPrice) {
        Product* productWanted;
        for(Product* product : products) {
            if(product->getId() == productId) {
                productWanted = product;
                break;
            }
        }
        if(productWanted->getQuantity() >= quantity) {
            if(inputPrice >= quantity * productWanted->getPrice()) {
                productWanted->setQuantity(productWanted->getQuantity() - quantity);
                cout<<"Product bought successfully. Balance : "<<inputPrice - (quantity * productWanted->getPrice())<<endl;
                return true;
            } else {
                cout<<"Not enough money to buy the item"<<endl;
                return false;
            }
        } else {
            cout<<"Not enough Quantity"<<endl;
            return false;
        }
    }
};

int main() {
    Product* redBull =  new Product(1,100, 10, "Red Bull");
    Product* sting = new Product(2, 50, 10, "Sting");
    VendingMachine* v1 = new VendingMachine(1, {redBull, sting});
    v1->buy(1, 5,600);
    v1->buy(1,40,100);
    v1->buy(1, 4, 350);
}