#include <iostream>
#include <string>
using namespace std;

// ---------------- Product Class ----------------
class House {
private:
    string walls;
    string roof;
    string floor;

public:
    void setWalls(const string& w) { walls = w; }
    void setRoof(const string& r) { roof = r; }
    void setFloor(const string& f) { floor = f; }

    void show() const {
        cout << "House with " << walls << ", " << roof << ", and " << floor << "." << endl;
    }
};

// ---------------- Abstract Builder ----------------
class HouseBuilder {
public:
    virtual HouseBuilder* buildWalls() = 0;
    virtual HouseBuilder* buildRoof() = 0;
    virtual HouseBuilder* buildFloor() = 0;
    virtual House* getHouse() = 0;
    virtual ~HouseBuilder() {}
};

// ---------------- Concrete Builder ----------------
class WoodenHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    WoodenHouseBuilder() { house = new House(); }

    HouseBuilder* buildWalls() override {
        house->setWalls("wooden walls");
        return this;
    }

    HouseBuilder* buildRoof() override {
        house->setRoof("wooden roof");
        return this;
    }

    HouseBuilder* buildFloor() override {
        house->setFloor("wooden floor");
        return this;
    }

    House* getHouse() override {
        return house;
    }
};

class BrickHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    BrickHouseBuilder() { house = new House(); }

    HouseBuilder* buildWalls() override { house->setWalls("brick walls"); return this; }
    HouseBuilder* buildRoof() override { house->setRoof("concrete roof"); return this; }
    HouseBuilder* buildFloor() override { house->setFloor("marble floor"); return this; }

    House* getHouse() override { return house; }
};



// ---------------- Director Class ----------------
class Director {
private:
    HouseBuilder* builder;
public:
    Director(HouseBuilder* b) : builder(b) {}
    House* construct() {
        return builder->buildWalls()->buildRoof()->buildFloor()->getHouse();
    }
};

// ---------------- Client Code ----------------
int main() {
    HouseBuilder* builder = new BrickHouseBuilder();
    Director director(builder);

    House* house = director.construct();
    house->show();

    delete builder;
    delete house;

    return 0;
}
