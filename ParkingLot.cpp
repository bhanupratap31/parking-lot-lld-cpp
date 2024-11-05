#include <iostream>
#include <string>
#include <map>
#include "vehicle-type/Vehicle.cpp"

using namespace std;

class ParkingLot
{
private:
    map<int, map<int, map<string, Vehicle *>>> spots;
    int floors;
    int rows;
    int spotsPerRow;

public:
    ParkingLot(int floors, int rows, int spotsPerRow) : floors(floors), rows(rows), spotsPerRow(spotsPerRow) {}

    bool Park(Vehicle *vehicle, int floor, int row)
    {
        if (spots[floors][row].size() < spotsPerRow)
        {
            string numberPlate = vehicle->getNumberPlate();
            spots[floor][row][numberPlate] = vehicle;
            cout << vehicle->getType() << " parked at the floor " << floor << ", row " << row << "." << endl;
            return true;
        }
        else
        {
            cout << "This floor does not have any spot left to park. Try another floor" << endl;
            return false;
        }
    }
};