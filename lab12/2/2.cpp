#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double z = 0;

    for (int k = 6; k >= 1; --k) {
        double a = abs(sin(12 * k) * cos(abs(2 * k) / 3) + 4.21);
        double b = 2 * sin(k) * sin(2 * k - 1.5) * cos(2 * k + 1.5) - 6;
        z += sin(a) + b;
    }

    cout << "The value of variable z: " << z << endl;

    return 0;
}
