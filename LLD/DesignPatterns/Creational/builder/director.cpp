#include "concreteBuilders.cpp"

class Director {
public:
    void construct(HouseBuilder& builder) {
        builder.buildWalls();
        builder.buildRoof();
        builder.buildFloor();
    }
};