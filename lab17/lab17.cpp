#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // Enter a string
    cout << "Enter a string: ";
    string inputString;
    getline(cin, inputString);

    // Create an istringstream object for conversion
    istringstream inputStream(inputString);

    // Try to read the string as an int
    int intValue;
    inputStream >> intValue;

    // Check if the conversion to int was successful
    if (!inputStream.fail() && inputStream.eof()) {
        cout << "This is an integer: " << intValue << endl;
    }
    else {
        // If conversion to int fails, try float
        inputStream.clear(); // Clear error flags
        inputStream.seekg(0); // Reset the stream to the beginning

        float floatValue;
        inputStream >> floatValue;

        // Check if the conversion to float was successful
        if (!inputStream.fail() && inputStream.eof()) {
            cout << "This is a floating-point number: " << floatValue << endl;
        }
        else {
            cout << "Unable to convert to a number." << endl;
        }
    }

    return 0;
}
