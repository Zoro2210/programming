#include <iostream>

using namespace std;

int main() {
    // House 
    double width_house = 30.0;
    double height_house = 40.0;
    double number_floors = 2.5;
    double area_of_utility_rooms = 825.0;
    double price_house = 150000.0;

    // calculation of the total area
    double general_plane = width_house * height_house * number_floors;

    // Calculation of the cost of one square meter of living space
    double cost_of_one_square_meter = price_house / (general_plane - area_of_utility_rooms);

    // Outputting result
    cout << "The cost of one square meter of living space of the house: " << cost_of_one_square_meter << " m^2" << endl;

    return 0;
}
