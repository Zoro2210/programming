#include <iostream>
#include <cmath>
#include <limits>

// Function from variant 6
double fi8(double x) {
    return sin(x) * pow(cos(x), 2) * sin(x + 1.4) / 0.85 + 7.14;
}

int main() {
    int variantNumber = 6; // Variant number
    double stepSize = 0.1 * variantNumber; // Step size
    double x, y;

    // Displaying the table header
    std::cout << "x\t\ty" << std::endl;

    // Variables for tasks
    int countNegativeValues = 0;
    double maxNegativeValue = std::numeric_limits<double>::min();

    // Tabulation and task execution
    for (x = 0; x <= variantNumber; x += stepSize) {
        y = fi8(x);

        // Displaying the values of x, y
        std::cout << x << "\t\t" << y << std::endl;

        // Task to count negative values and find the maximum negative value
        if (y < 0) {
            countNegativeValues++;
            maxNegativeValue = std::max(maxNegativeValue, y);
        }
    }

    // Displaying the results of the tasks
    std::cout << "Number of negative values: " << countNegativeValues << std::endl;
    if (countNegativeValues > 0) {
        std::cout << "Maximum negative value: " << maxNegativeValue << std::endl;
    }
    else {
        std::cout << "No negative values found." << std::endl;
    }

    return 0;
}
