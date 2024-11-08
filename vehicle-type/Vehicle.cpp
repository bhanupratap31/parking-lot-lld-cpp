#include <iostream>
#include <string>
#include "VehicleType.cpp"
#include "Bike.cpp"
#include "Car.cpp"
#include "Truck.cpp"

using namespace std;

class Vehicle
{
protected:
    string numberPlate;
    VehicleType type;

public:
    virtual enum VehicleType getType() = 0;
    string getNumberPlate()
    {
        return numberPlate;
    }
};