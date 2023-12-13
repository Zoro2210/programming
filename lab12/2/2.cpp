#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Your variant number
    int i = 6;

    // Calculation of values a, b, i, z
    double a = 0.0;
    double b = 1.0;
    double z = 0.0;

    for (int k = 1; k <= i; ++k) {
        double x = k; // You may use a different value for x depending on your task

        // Formula for a
        double a_term = abs(sin(12 * x) * cos(abs(2 * x)) / (3 * abs(4.21)));
        if (!isnan(a_term)) {
            a += a_term;
        }

        // Formula for b
        double b_term = 2 * sin(x) * sin(2 * x - 1.5) * cos(2 * x + 1.5) - 6 /
            (pow(cos(x), 3.0 / 2.1) + pow(cos(x), 2.0 / 1.1) - 8.3 * sin(3 * x + 1));

        if (!isnan(b_term) && !isinf(b_term)) {
            b *= b_term;
        }
    }

    // Calculation of the value z
    z = sin(a) + b;

    // Output the results
    cout << "i: " << i << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "z: " << z << endl;

    return 0;
}
