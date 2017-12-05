#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main () {

    int checksum = 0;

    while (!cin.eof()) {

        string line;
        getline (cin, line);
        istringstream iss(line);

        vector<int> lineIntegers;
        int current = 0;

        while (iss >> current) {
            lineIntegers.push_back(current);
        }

        for (size_t i = 0; i < lineIntegers.size(); i++) {

            for (int j = 0; j < lineIntegers.size(); j++) {
                if (lineIntegers.at(i) > lineIntegers.at(j) && (lineIntegers.at(i) % lineIntegers.at(j)) == 0) {
                    checksum += (lineIntegers.at(i) / lineIntegers.at(j));
                    cout << "Current checksum: " << checksum << endl;
                }
            }
        }
    }

    cout << "The checksum value is " << checksum << endl;
}

void spreadsheet_checksum () {


    int checksum = 0;

    while (!cin.eof()) {

        string curLine;
        getline(cin, curLine);
        istringstream iss(curLine);

        int current = 0, lineMin = 0, lineMax = 0;
        iss >> current;
        lineMin = lineMax = current;

        while (iss >> current) {

            if (current > lineMax) lineMax = current;
            else if (current < lineMin) lineMin = current;

            cout << current << " ";
        }

        checksum += (lineMax - lineMin);
    }

    cout << "The spreadsheet checksum is " << checksum << endl;
}