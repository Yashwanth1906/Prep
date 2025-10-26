#include "director.cpp"

int main() {
    Director director;

    WoodenHouseBuilder woodenBuilder;
    director.construct(woodenBuilder);
    House* woodenHouse = woodenBuilder.getHouse();
    woodenHouse->showHouse();

    BrickHouseBuilder brickBuilder;
    director.construct(brickBuilder);
    House* brickHouse = brickBuilder.getHouse();
    brickHouse->showHouse();
    
    delete woodenHouse;
    delete brickHouse;
}