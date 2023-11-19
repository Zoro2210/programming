#include <iostream>
#include <iomanip>

using namespace std;

// Constants representing weights and dimensions
const float PERSON_WT = 170.0;
const float LBS_PER_GAL = 6.7;
const float EMPTY_WEIGHT = 9887.0;
const float EMPTY_MOMENT = 3185853.0;

// Function to calculate the moment contributed by the crew
float CrewMoment(int crew) {
    return (crew * PERSON_WT * 143);
}

// Function to calculate the moment contributed by passengers
float PassengerMoment(int passengers) {
    float distance = 0;

    if (passengers >= 0 && passengers <= 8) {
        for (int i = 0; i < passengers; ++i) {
            if (i < 2) {
                distance += PERSON_WT * 265;
            }
            else if (i < 4) {
                distance += PERSON_WT * 219;
            }
            else if (i < 6) {
                distance += PERSON_WT * 295;
            }
            else {
                distance += PERSON_WT * 341;
            }
        }
    }

    return distance;
}

// Function to calculate the moment contributed by cargo
float CargoMoment(float closet, float baggage) {
    return (closet * 182 + baggage * 386);
}

// Function to calculate the moment contributed by fuel
float FuelMoment(float fuel) {
    float distance;

    // Calculation of fuel moment depending on different fuel levels
    if (fuel <= 59) {
        distance = 314.6 * fuel;
    }
    else if (fuel <= 360) {
        distance = 305.8 - 0.01233 * (fuel - 60);
    }
    else if (fuel <= 520) {
        distance = 303.0 + 0.12500 * (fuel - 361);
    }
    else {
        distance = 323.0 - 0.04444 * (fuel - 521);
    }

    return (fuel * LBS_PER_GAL * distance);
}

// Function to print warnings based on total weight and center of gravity
void PrintWarning(float weight, float centerOfGravity) {
    if (weight > 14900.0) {
        cout << "Warning: The aircraft is too heavy!" << endl;
    }
    if (centerOfGravity < 280.0 || centerOfGravity > 350.0) {
        cout << "Warning: The center of gravity is too far from the nose of the aircraft!" << endl;
    }
}

// Main function where user input and calculations take place
int main() {
    int crew, passengers;
    float closet, baggage, fuel;

    // User input for crew, passengers, closet weight, baggage weight, and fuel quantity
    cout << "Enter the number of crew members: ";
    cin >> crew;
    cout << "Enter the number of passengers: ";
    cin >> passengers;
    cout << "Enter the weight of the closet: ";
    cin >> closet;
    cout << "Enter the weight of the baggage: ";
    cin >> baggage;
    cout << "Enter the quantity of fuel in gallons: ";
    cin >> fuel;

    // Calculation of total weight, including crew, passengers, cargo, baggage, and fuel
    float totalWeight = EMPTY_WEIGHT +
        (passengers + crew) * PERSON_WT +
        closet + baggage + fuel * LBS_PER_GAL;
    // Calculation of the center of gravity based on various contributions
    float centerOfGravity = (CrewMoment(crew) + PassengerMoment(passengers) +
        CargoMoment(closet, baggage) + FuelMoment(fuel) + EMPTY_MOMENT) / totalWeight;

    // Output of total weight and center of gravity with two decimal places
    cout << fixed << setprecision(2);
    cout << "Total weight: " << totalWeight << endl;
    cout << "Center of gravity: " << centerOfGravity << endl;

    // Output of warnings based on total weight and center of gravity
    PrintWarning(totalWeight, centerOfGravity);

    return 0;
}
