#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Function to calculate the value of a_kn
double calculateElement(int k, int n) {
    double x = 0.5; // Example value for x, you can change it as needed
    double result = abs(k * n) + cos(2 * x) - pow(abs(pow(n, 3) + 2 * sin(x / 1.2 - 3.4)), 1.0 / 1.2) + 10.51 * cos(abs(3 * x)) + sin(k * x) + 12 * n;
    return result;
}

int main() {
    // Create a matrix
    double matrix[ROWS][COLS];

    // Fill the matrix with values of a_kn
    for (int k = 1; k <= ROWS; ++k) {
        for (int n = 1; n <= COLS; ++n) {
            matrix[k - 1][n - 1] = calculateElement(k, n);
        }
    }

    // Display the matrix on the screen
    cout << "Matrix:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(15) << matrix[i][j];
        }
        cout << '\n';
    }

    // Calculate the product of squares for |akn| < 3
    double product = 1.0;
    for (int k = 1; k <= ROWS; ++k) {
        for (int n = 1; n <= COLS; ++n) {
            if (abs(matrix[k - 1][n - 1]) < 3) {
                product *= pow(matrix[k - 1][n - 1], 2);
            }
        }
    }

    // Display the result
    cout << "\nProduct of squares for |akn| < 3: " << product << endl;

    return 0;
}
