#include <iostream>
#include <vector>
#include <string>

// Structure representing a record for a computer
struct ComputerRecord {
    std::string modelName;
    int yearOfManufacture;
    float price;
    std::string color;  // In the context of computers, this could represent a case color or any other relevant attribute
};

int main() {
    // Creating an array of six to seven computer records
    std::vector<ComputerRecord> computerArray = {
        {"Dell Inspiron", 2019, 800.0, "Black"},
        {"HP Pavilion", 2020, 900.0, "Silver"},
        {"Lenovo ThinkPad", 2018, 1200.0, "Gray"},
        {"Apple MacBook Air", 2021, 1200.0, "Silver"},
        {"Asus ROG Strix", 2020, 1500.0, "Black"},
        {"Acer Aspire", 2019, 700.0, "White"}
    };

    // Displaying information about computers in the inventory
    std::cout << "Computer Inventory:\n";
    for (const auto& computer : computerArray) {
        std::cout << "Model: " << computer.modelName << ", Year: " << computer.yearOfManufacture
            << ", Price: $" << computer.price << ", Color: " << computer.color << "\n";
    }

    // Search criteria: Black computers manufactured in 2020
    std::cout << "\nBlack Computers Manufactured in 2020:\n";
    for (const auto& computer : computerArray) {
        if (computer.color == "Black" && computer.yearOfManufacture == 2020) {
            std::cout << "Model: " << computer.modelName << "\n";
        }
    }

    return 0;
}
