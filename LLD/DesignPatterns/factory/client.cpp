#include <iostream>
using namespace std;
#include "vehicleFactory.cpp"
int main() {
  string input;
  cin>>input;
  Vehicle* vehicle = VehicleFactory::getVehicle(input);
  vehicle->createVehicle();
}
