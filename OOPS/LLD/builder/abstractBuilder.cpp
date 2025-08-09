#include "product.cpp"

class HouseBuilder {
public:
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildFloor() = 0;
    virtual House* getHouse() = 0;
    virtual ~HouseBuilder() {}
};