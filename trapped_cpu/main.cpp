#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void readJumpList(vector<int>& jumps) {
    while (!cin.eof()) {
        string number;
        getline(cin, number);

        if (number.empty())
            break;

        int in = strtol(number.c_str(), NULL, 10);
        jumps.push_back(in);
    }
}

int calculateEscapeSteps(vector<int> jumps) {

    int steps = 0;
    int idx = 0;

    while (idx < jumps.size() && idx >= 0) {
        int currentJump = jumps[idx];

        if (abs(jumps[idx] >= 3))
            jumps[idx]--;
        else
            jumps[idx]++;

        idx += currentJump;
        //cout << "jumping: " << currentJump << endl;
        steps++;
    }

    return steps;
}

int main () {

    vector<int> cpuJumps;
    readJumpList(cpuJumps);

    cout << "There were " << cpuJumps.size() << " jumps stored in the jump list." << endl;

    int steps = calculateEscapeSteps(cpuJumps);
    cout << "The CPU can escape in " << steps << " steps." << endl;
}