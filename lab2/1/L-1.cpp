#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    double fuel1, fuel2, fuel3, fuel4, distanceStart, distanceEnd;

    // Entering data from your gas stations
    fuel1 = 11.7;
    fuel2 = 14.3;
    fuel3 = 12.2;
    fuel4 = 8.5;

    // Entering the initial and final odometer readings
    distanceStart = 67308.0;
    distanceEnd = 68750.5;

    // Calculation of total fuel consumption
    double totalFuelConsumed = fuel1 + fuel2 + fuel3 + fuel4;

    // Calculation of total mileage
    double totalDistanceTraveled = distanceEnd - distanceStart;

    // Calculation of fuel consumption per kilometer
    double fuelEfficiency = totalFuelConsumed / totalDistanceTraveled;

    // Outputting the result
    cout << "Total fuel consumption: " << fixed << setprecision(2) << totalFuelConsumed << " l" << endl;
    cout << "Total mileage: " << totalDistanceTraveled << " km" << endl;
    cout << "Your fuel consumption: " << fixed << setprecision(2) << fuelEfficiency << " km/l" << endl;

    return 0;
}