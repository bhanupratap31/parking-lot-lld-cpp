#include <iostream>
#include <string>
#include "Vehicle.cpp"

using namespace std;

class Bike : public Vehicle
{
    Bike(string numberPlate)
    {
        this->numberPlate = numberPlate;
    }

    enum VehicleType getType()
    {
        return VehicleType::BIKE;
    }
};