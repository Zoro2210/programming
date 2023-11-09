#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double i;
    cout << "Enter the value i: ";
    cin >> i;

    // Calculation of distances between points
    double AB = sqrt(pow(i, 2) + pow(i - 1, 2));
    double AC = sqrt(pow(i, 2) + pow(i + 1, 2));
    double BC = sqrt(pow(2 * i, 2) + 2 * 2);

    // Semiperimeter of a triangle
    double p = (AB + AC + BC) / 2;

    // Area of ​​the triangle
    double S = sqrt(p * (p - AB) * (p - AC) * (p - BC));

    // Bisector of Wa
    double Wa = (2 * BC * AC) / (BC + AC) * sqrt(BC * AC * p * (p - AB)) / (BC + AC - AB);

    // The radius of the circle R
    double R = (AB * BC * AC) / (4 * S);

    cout << "Bisector of Wa: " << Wa << endl;
    cout << "The radius of the circle R: " << R << endl;

    return 0;
}
