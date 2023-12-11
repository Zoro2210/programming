#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char typeOfWork;
    double x;

    // Input type of work
    cout << "Enter the type of work (A, B, C): ";
    cin >> typeOfWork;

    // Input the value of x
    cout << "Enter the value of x: ";
    cin >> x;

    double payment, taxRate, tax, netPayment;

    // Go to the corresponding label based on the type of work
switch_label:
    switch (typeOfWork) {
    case 'A':
        payment = 100 * fabs(cos(x) * cos(x) * sin(2 * x - 1) + 4.29 * (6) + 50);
        taxRate = 0.10;
        goto calculate;
    case 'B':
        payment = 150 * fabs(cos(x * x + 1) - fabs(sin(2 * x) - 5.76) + 100);
        taxRate = 0.15;
        goto calculate;
    case 'C':
        payment = 200 * fabs(sin(x) - pow(cos(x), 3) * sin(x * x - 4.2) + 4.27 + 135);
        taxRate = 0.20;
        goto calculate;
    default:
        cerr << "Invalid type of work. Enter A, B, or C." << endl;
        return 1;  // Return an error
    }

    // Calculate tax and net payment
calculate:
    tax = payment * taxRate;
    netPayment = payment - tax;

    // Output the results
    cout << "Accrued amount: " << payment << endl;
    cout << "Tax amount (" << (taxRate * 100) << "%): " << tax << endl;
    cout << "Amount to be paid: " << netPayment << endl;

    return 0;
}
