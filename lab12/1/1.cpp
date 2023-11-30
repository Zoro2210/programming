#include <iostream>
#include <cctype> // For the isdigit() function

using namespace std;

int main() {
    char letter;

    do {
        cout << "Enter a letter: ";
        cin >> letter;

        if (isalpha(letter)) { // Check if the input is a letter
            letter = toupper(letter); // Convert to uppercase

            switch (letter) {
            case 'A': case 'B': case 'C':
                cout << "The letter " << letter << " corresponds to the digit 2 on the phone." << endl;
                break;
            case 'D': case 'E': case 'F':
                cout << "The letter " << letter << " corresponds to the digit 3 on the phone." << endl;
                break;
            case 'G': case 'H': case 'I':
                cout << "The letter " << letter << " corresponds to the digit 4 on the phone." << endl;
                break;
            case 'J': case 'K': case 'L':
                cout << "The letter " << letter << " corresponds to the digit 5 on the phone." << endl;
                break;
            case 'M': case 'N': case 'O':
                cout << "The letter " << letter << " corresponds to the digit 6 on the phone." << endl;
                break;
            case 'P': case 'R': case 'S':
                cout << "The letter " << letter << " corresponds to the digit 7 on the phone." << endl;
                break;
            case 'T': case 'U': case 'V':
                cout << "The letter " << letter << " corresponds to the digit 8 on the phone." << endl;
                break;
            case 'W': case 'X': case 'Y':
                cout << "The letter " << letter << " corresponds to the digit 9 on the phone." << endl;
                break;
            default:
                cout << "The entered letter is not supported. Enter Q or Z to exit." << endl;
            }
        }
        else if (letter != 'Q' && letter != 'Z') {
            cout << "Invalid character entered. Enter Q or Z to exit." << endl;
        }

    } while (letter != 'Q' && letter != 'Z');

    cout << "Exit." << endl;

    return 0;
}