#include <iostream>
#include <iomanip>

int main() {
    double gallonsUK = 1.0;
    double liters;
    int numRows = 10;

    std::cout << "Gallons (UK) | Liters" << std::endl;
    std::cout << "---------------------" << std::endl;

    for (int i = 0; i < numRows; ++i) {
        liters = gallonsUK * 4.546; // Переведення галонів британських в літри

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(12) << gallonsUK << " | " << std::setw(6) << liters << std::endl;

        gallonsUK += 1.0;
    }

    return 0;
}
