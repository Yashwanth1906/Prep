#include "abstractBuilder.cpp"

class WoodenHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    WoodenHouseBuilder() { house = new House(); }

    void buildWalls() override { house->setWalls("wooden walls"); }
    void buildRoof() override { house->setRoof("wooden roof"); }
    void buildFloor() override { house->setFloor("wooden floor"); }

    House* getHouse() override { return house; }
};

class BrickHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    BrickHouseBuilder() { house = new House(); }

    void buildWalls() override { house->setWalls("brick walls"); }
    void buildRoof() override { house->setRoof("concrete roof"); }
    void buildFloor() override { house->setFloor("marble floor"); }

    House* getHouse() override { return house; }
};
