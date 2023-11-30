#include <iostream>
#include <sstream>

int main() {
    std::string inputString;

    // Input a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    try {
        // Attempt to convert the string to an int
        int intValue = std::stoi(inputString);
        std::cout << "Converted to integer: " << intValue << std::endl;
    }
    catch (const std::invalid_argument&) {
        try {
            // Attempt to convert the string to a float
            float floatValue = std::stof(inputString);
            std::cout << "Converted to float: " << floatValue << std::endl;
        }
        catch (const std::invalid_argument&) {
            // Display an error message if conversion fails
            std::cout << "Invalid input. Unable to convert to int or float." << std::endl;
        }
    }

    return 0;
}
