#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int main() {
    char input;

    do {
        cout << "Enter a letter: ";
        cin >> input;

        if (isalpha(input) || input == 'Q' || input == 'Z') {
            if (isalpha(input)) {
                input = toupper(input); // convert to uppercase

                int result = 0;
                if (input >= 'A' && input <= 'C') {
                    result = 2;
                }
                else if (input >= 'D' && input <= 'F') {
                    result = 3;
                }
                else if (input >= 'G' && input <= 'I') {
                    result = 4;
                }
                else if (input >= 'J' && input <= 'L') {
                    result = 5;
                }
                else if (input >= 'M' && input <= 'O') {
                    result = 6;
                }
                else if (input >= 'P' && input <= 'S') {
                    result = 7;
                }
                else if (input >= 'T' && input <= 'U') {
                    result = 8;
                }
                else if (input == 'W' || input == 'X' || input == 'Y' || input == 'Z') {
                    result = 9;
                }
                else {
                    cout << "The entered letter does not correspond to any digit on the phone." << endl;
                    continue;
                }

                cout << "The letter " << input << " corresponds to the digit " << result << " on the phone." << endl;

            }
            else if (input == 'Q' || input == 'Z') {
                cout << "Exiting." << endl;
                break;
            }

        }
        else {
            cout << "Invalid input. Enter a letter:" << endl;
        }

    } while (true);

    return 0;
}