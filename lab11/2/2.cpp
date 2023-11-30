#include <iostream>
using namespace std;

int main() {

start:
    char state[3];
    cout << "Enter the abbreviation of the US state: ";
    cin >> state;

    // Check the first letter of the abbreviation
    switch (state[0]) {
    case 'A':
        if (state[1] == 'L') {
            cout << "Alabama";
        }
        else if (state[1] == 'R') {
            cout << "Arkansas";
        }
        else {
            cout << "Abbreviation entered incorrectly";
            goto error;
        }
        break;
    case 'B':
        if (state[1] == 'C') {
            cout << "North Carolina";
        }
        else if (state[1] == 'D') {
            cout << "Kentucky";
        }
        else {
            cout << "Abbreviation entered incorrectly";
            goto error;
        }
        break;
        
    default:
        cout << "Abbreviation entered incorrectly";
        goto error;
    }

    return 0;

error:
    cout << "Enter the abbreviation again: ";
    cin >> state;
    goto start;
}
