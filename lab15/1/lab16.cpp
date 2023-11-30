#include <iostream>
#include <cmath>

int main() {
    const int n = 7; // Size of the array
    double array[n];

    // Filling the array using the given formula
    for (int k = 1; k <= n; ++k) {
        double x = k; // x = k
        array[k - 1] = (std::cos(2.1 * x) * std::sin(std::abs(x))) / (0.15 - 5.8 * k);
    }

    // Displaying the array
    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Finding the index of the fifth negative element
    int negativeCount = 0;
    int fifthNegativeIndex = -1;

    for (int i = 0; i < n; ++i) {
        if (array[i] < 0) {
            ++negativeCount;
            if (negativeCount == 5) {
                fifthNegativeIndex = i + 1; // +1 because indexing starts from 0
                break;
            }
        }
    }

    // Displaying the results
    if (fifthNegativeIndex != -1) {
        std::cout << "Index of the fifth negative element: " << fifthNegativeIndex << std::endl;
    }
    else {
        std::cout << "The array does not have enough negative elements." << std::endl;
    }

    return 0;
}
