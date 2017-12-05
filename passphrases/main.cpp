#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

bool passphraseIsLegal(string passphrase) {
    istringstream iss(passphrase);
    string phrase;

    while (iss >> phrase) {

        // find first match
        size_t pos = passphrase.find(phrase);
        cout << "first match at: " << pos << endl;

        if (passphrase.find(phrase, (pos+1)) != string::npos)
            return false;
    }

    return true;
}

bool containsAnagrams(string passphrase) {

    istringstream iss(passphrase);
    string phrase;

    while (iss >> phrase) {
        int matches = 0;

        // sort the current passphrase
        sort(phrase.begin(), phrase.end());

        istringstream iss2(passphrase);
        string phrase2;

        while (iss2 >> phrase2) {
            sort(phrase2.begin(), phrase2.end());

            if (phrase == phrase2)
                matches++;
        }

        if (matches > 1)
            return true;
    }

    return false;
}

int main () {

    int legalPhrases = 0;

    while (!cin.eof()) {
        string input;
        getline(cin, input);

        if (passphraseIsLegal(input) && !containsAnagrams(input))
            legalPhrases++;
    }

    cout << "Legal passphrases found: " << legalPhrases << endl;
}