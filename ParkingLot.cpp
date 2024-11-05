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

    bool Leave(Vehicle *vehicle)
    {
        for (int i = 0; i < floors; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                string numberPlate = vehicle->getNumberPlate();
                if (spots[i][j].find(numberPlate) != spots[i][j].end())
                {
                    spots[i][j].erase(numberPlate);
                    cout << vehicle->getType() << " left successfully. " << endl;
                    return true;
                }
            }
        }
        cout << vehicle->getType() << " not found" << endl;
        return false;
    }

    int availableSpots(int floor)
    {
        int count = 0;
        for (int r = 0; r < rows; r++)
        {
            count += spotsPerRow - (int)spots[floor][r].size();
        }
        return count;
    }

    void Clear()
    {
        for (auto &outer : spots)
        {
            outer.second.clear();
        }
        spots.clear();
    }
};