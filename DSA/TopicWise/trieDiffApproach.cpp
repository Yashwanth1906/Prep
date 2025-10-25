#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void sleep() = 0;
    void run() {
        cout<<"running"<<endl;
    }
};

class Cat : public Animal {
public:
    void sleep () override {
        cout<<"Sleeping"<<endl;
    }
    void steel() {

    }
};


int main() {
    Animal* a = new Cat();
    a->sleep();

}