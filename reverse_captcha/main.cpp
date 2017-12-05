#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main () {

    string number;
    getline(cin, number);
    int cmpDistance = number.length() / 2;
    int current = 0, compare = 0, index = 0;
    int captcha = 0;

    while (index < number.length()) {

        current = strtol(number.substr(index, 1).c_str(), NULL, 10);
        
        if (index+cmpDistance < number.length()) {
            compare = strtol(number.substr(index+cmpDistance, 1).c_str(), NULL, 10);
        } else {
            int cmpIdx = (index+cmpDistance) - number.length();
            compare = strtol(number.substr(cmpIdx, 1).c_str(), NULL, 10);
        }

        cout << "current: " << current << ", compare: " << compare << endl;
        if (current == compare)
            captcha += current;

        index++;
    }

    cout << "The captcha result is " << captcha << endl;
}

void reverse_captcha () {

    int startnum = 0, current = 0, next = 0;
    int sum = 0;

    startnum = current = cin.get();
    next = cin.get();
    
    do {

        if (current == next) {
            string num = "";
            num += (char) current;
            int value = strtol(num.c_str(), NULL, 10);
            sum += value;
        }

        current = next;
        
    } while ((next = cin.get()) != '\n');

    if (current == startnum) {
        string num = "";
        num += (char) current;
        int value = strtol(num.c_str(), NULL, 10);
        sum += value;
    }

    cout << "The reverse captcha sum is: " << sum << endl;
}