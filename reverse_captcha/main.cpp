#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

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