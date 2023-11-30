#include <iostream>
#include <climits> // for using the constant INT_MAX

const int numYears = 10; // Number of years
const int variantNumber = 1; // Your variant number

int main() {
    int profits[numYears];
    int maxLossYear = 0; // Year with the largest losses
    int maxLoss = INT_MAX; // Initial value for finding the largest losses
    int sumInRange = 0; // Sum of profits within the range 0 < y < 710

    std::cout << "Year\tProfit" << std::endl;

    for (int k = 0; k < numYears; ++k) {
        int year = 2000 + k;
        int profit = 100 * variantNumber + 9 * year;

        profits[k] = profit;

        // Displaying the year and profit
        std::cout << year << "\t" << profit << std::endl;

        // Calculating the sum of profits within the range 0 < y < 710
        if (profit > 0 && profit < 710) {
            sumInRange += profit;
        }

        // Finding the year with the largest losses
        if (profit < maxLoss) {
            maxLoss = profit;
            maxLossYear = year;
        }
    }

    // Displaying the sum of profits within the range 0 < y < 710
    std::cout << "Sum of profits within the range 0 < y < 710: " << sumInRange << " monetary units" << std::endl;

    // Displaying the year with the largest losses
    if (maxLoss < 0) {
        std::cout << "Year with the largest losses: " << maxLossYear << std::endl;
    }
    else {
        std::cout << "No losses were incurred." << std::endl;
    }

    return 0;
}
