#include <iostream>
using namespace std;

int main() {
    char state[3];
    int choice;

start:
    cout << "Enter the abbreviation of the US state: ";
    cin >> state;

    // Check the first letter of the abbreviation
    switch (state[0]) {
    case 'A':
        switch (state[1]) {
        case 'L':
            cout << "Alabama";
            break;
        case 'R':
            cout << "Arkansas";
            break;
        default:
            cout << "Abbreviation entered incorrectly";
            goto start;
        }
        break;
    case 'N':
        switch (state[1]) {
        case 'C':
            cout << "North Carolina";
            break;
        case 'D':
            cout << "Kentucky";
            break;
        default:
            cout << "Abbreviation entered incorrectly";
            goto start;
        }
        break;
       
    default:
        cout << "Abbreviation entered incorrectly";
        goto start;
    }

    // Display a menu
    cout << endl;
    cout << "Would you like to:" << endl;
    cout << "1. Enter another abbreviation" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;

    // Process the user's choice
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice";
        cout << endl;
        cout << "Would you like to:" << endl;
        cout << "1. Enter another abbreviation" << endl;
        cout << "2. Quit" << endl;
        cin >> choice;
    }

    if (choice == 1) {
        goto start;
    }
    else {
        return 0;
    }
}
