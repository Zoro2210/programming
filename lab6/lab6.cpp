#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double gallonsUK = 1.0;
    double gallonsUS;
    double liters;
    int numRows = 10;
    double step;

    cout << "Enter the step size: ";
    cin >> step;

    cout << "Gallons (UK) | Gallons (US) | Liters" << endl;
    cout << "------------------------------------" << endl;

    for (int i = 0; i < numRows; ++i) {
        gallonsUS = gallonsUK * 1.20095; // Conversion from UK gallons to US gallons
        liters = gallonsUK * 4.546; // Conversion from UK gallons to liters

        cout << fixed << setprecision(2);
        cout << setw(12) << gallonsUK << " | " << setw(12) << gallonsUS << " | " << setw(6) << liters << endl;

        gallonsUK += step;
    }

    return 0;
}
