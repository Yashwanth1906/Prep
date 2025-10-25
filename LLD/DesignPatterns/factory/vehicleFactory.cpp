#include "vehicleFactory.hpp"

Vehicle* VehicleFactory::getVehicle(string input) {
    Vehicle* vehicle;
    if(input == "car") {
        vehicle = new Car();
    } else if(input == "bike") {
        vehicle = new Bike();
    }
    return vehicle;
}