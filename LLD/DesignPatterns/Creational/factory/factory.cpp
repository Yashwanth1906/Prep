#include <iostream>
#include <string>
using namespace std;

// ---------------- Base Class ----------------
class Shape {
public:
    virtual void draw() = 0; // pure virtual (abstract)
    virtual ~Shape() {}
};

// ---------------- Concrete Classes ----------------
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle 🟢" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle 🟥" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square 🟦" << endl;
    }
};

// ---------------- Factory Class ----------------
class ShapeFactory {
public:
    static Shape* getShape(const string& shapeType) {
        if (shapeType == "circle") {
            return new Circle();
        } 
        else if (shapeType == "rectangle") {
            return new Rectangle();
        } 
        else if (shapeType == "square") {
            return new Square();
        }
        else {
            return nullptr;
        }
    }
};

// ---------------- Client Code ----------------
int main() {
    Shape* shape1 = ShapeFactory::getShape("circle");
    Shape* shape2 = ShapeFactory::getShape("rectangle");
    Shape* shape3 = ShapeFactory::getShape("square");

    if (shape1) shape1->draw();
    if (shape2) shape2->draw();
    if (shape3) shape3->draw();

    // cleanup
    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
