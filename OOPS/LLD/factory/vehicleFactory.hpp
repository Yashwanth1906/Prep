#pragma once
#include "bike.hpp"
#include "car.hpp"
#include <iostream>
using namespace std;

class VehicleFactory {
public:
    static Vehicle* getVehicle(string input);
};