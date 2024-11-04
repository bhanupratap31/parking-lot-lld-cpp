#include <iostream>
#include <string>
#include "Vehicle.cpp"
using namespace std;

class Truck : public Vehicle
{
public:
    Truck(string numberPlate)
    {
        this->numberPlate = numberPlate;
    }
    enum VehicleType getType()
    {
        return VehicleType::BIKE;
    }
};