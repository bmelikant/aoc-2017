#include <iostream>
#include <sstream>

using namespace std;

int main () {

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