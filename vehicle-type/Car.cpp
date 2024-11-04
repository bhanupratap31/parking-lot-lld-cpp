#include <iostream>
#include <string>
#include "Vehicle.cpp"
using namespace std;

class Car : public Vehicle
{
    Car(string numberPlate)
    {
        this->numberPlate = numberPlate;
    }

    enum VehicleType getType()
    {
        return VehicleType::CAR;
    }
};