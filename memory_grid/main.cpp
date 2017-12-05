#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>

using namespace std;

struct Coordinate {
    int x,y;
};

enum Direction { UP, DOWN, LEFT, RIGHT };

Coordinate findSpiralLocation(int target) {

    Direction currentDirection = RIGHT;
    Coordinate currentCoordinate = { 0, 0 };
    int currentStepCount = 1;
    int stage = 1;
    int memoryIdx = 1;

    cout << "x: " << currentCoordinate.x << ", y: " << currentCoordinate.y << endl;

    while (memoryIdx < target) {

        if (currentDirection == RIGHT) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.x++;
                memoryIdx++;

                if (memoryIdx == target)
                    return currentCoordinate;
            }

            currentDirection = UP;
        }

        else if (currentDirection == UP) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.y--;
                memoryIdx++;

                if (memoryIdx == target)
                    return currentCoordinate;
            }

            currentDirection = LEFT;
        }

        else if (currentDirection == LEFT) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.x--;
                memoryIdx++;

                if (memoryIdx == target)
                    return currentCoordinate;
            }

            currentDirection = DOWN;
        }
        
        else if (currentDirection == DOWN) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.y++;
                memoryIdx++;

                if (memoryIdx == target)
                    return currentCoordinate;
            }

            currentDirection = RIGHT;
        }

        if (stage == 1) stage++;
        else if (stage == 2) { stage = 1; currentStepCount++; }

        cout << "x: " << currentCoordinate.x << ", y: " << currentCoordinate.y << endl;
    } 
}

int sumClosestNeighbors(Coordinate data, map<string, int> valueMap) {

    int x = data.x-1, y = data.y-1, sum = 0;

    for (int i = y; i <= data.y+1; i++) {
        for (int j = x; j <= data.x+1; j++) {
            if (x == data.x && y == data.y)
                continue;
            else {
                ostringstream oss;
                oss << j << "," << i;
                cout << "checking key " << oss.str() << endl;

                if (valueMap.find(oss.str()) != valueMap.end()) {
                    cout << "found key " << oss.str() << endl;
                    sum += valueMap[oss.str()];
                }
            }
        }
    }

    cout << "sum: " << sum << endl;
    return sum;
}

int firstValueGreaterThan(int target) {

    map<string, int> coordinateData;
    Direction currentDirection = RIGHT;
    Coordinate currentCoordinate = { 0, 0 };
    int currentStepCount = 1;
    int stage = 1;
    int memoryIdx = 1;
    
    cout << "x: " << currentCoordinate.x << ", y: " << currentCoordinate.y << endl;
    coordinateData["0,0"] = 1;

    while (memoryIdx < target) {

        if (currentDirection == RIGHT) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.x++;
                memoryIdx++;

                ostringstream oss;
                oss << "" << currentCoordinate.x << "," << currentCoordinate.y;
                cout << "map key: " << oss.str() << endl;
                coordinateData[oss.str()] = sumClosestNeighbors(currentCoordinate, coordinateData);

                if (coordinateData[oss.str()] > target)
                    return coordinateData[oss.str()];
            }

            currentDirection = UP;
        }

        else if (currentDirection == UP) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.y--;
                memoryIdx++;

                ostringstream oss;
                oss << "" << currentCoordinate.x << "," << currentCoordinate.y;
                cout << "map key: " << oss.str() << endl;
                coordinateData[oss.str()] = sumClosestNeighbors(currentCoordinate, coordinateData);

                if (coordinateData[oss.str()] > target)
                    return coordinateData[oss.str()];
            }

            currentDirection = LEFT;
        }

        else if (currentDirection == LEFT) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.x--;
                memoryIdx++;

                ostringstream oss;
                oss << "" << currentCoordinate.x << "," << currentCoordinate.y;
                cout << "map key: " << oss.str() << endl;
                coordinateData[oss.str()] = sumClosestNeighbors(currentCoordinate, coordinateData);

                if (coordinateData[oss.str()] > target)
                    return coordinateData[oss.str()];
            }

            currentDirection = DOWN;
        }
        
        else if (currentDirection == DOWN) {

            for (int i = 0; i < currentStepCount; i++) {
                currentCoordinate.y++;
                memoryIdx++;
  
                ostringstream oss;
                oss << "" << currentCoordinate.x << "," << currentCoordinate.y;
                cout << "map key: " << oss.str() << endl;
                coordinateData[oss.str()] = sumClosestNeighbors(currentCoordinate, coordinateData);

                if (coordinateData[oss.str()] > target)
                    return coordinateData[oss.str()];
            }

            currentDirection = RIGHT;
        }

        if (stage == 1) stage++;
        else if (stage == 2) { stage = 1; currentStepCount++; }

        cout << "x: " << currentCoordinate.x << ", y: " << currentCoordinate.y << endl;
    }
}

int main () {
    int index = 0;
    cin >> index;

    Coordinate memCoordinate = findSpiralLocation(index);
    cout << "x: " << memCoordinate.x << ", y: " << memCoordinate.y << endl;
    cout << "Manhattan distance: " << abs(memCoordinate.x) + abs(memCoordinate.y) << endl;

    int firstGreater = firstValueGreaterThan(index);
    cout << "First greater than target: " << firstGreater << endl;
}