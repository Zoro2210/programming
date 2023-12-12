#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Input variable values
    double x, a, b;

    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    // Evaluate the expression
    double y;

    if (x < a) {
        y = pow(cos(b * x), 2);
    }
    else if (a <= x && x <= b) {
        y = sqrt(x - a);
    }
    else {
        y = fabs((a * x - 2 * b) / (pow(x, 2) + pow(b, 2)));
    }

    // Output the result
    cout << "The value of the expression for x=" << x << ", a=" << a << ", b=" << b << " is " << y << endl;

    return 0;
}
