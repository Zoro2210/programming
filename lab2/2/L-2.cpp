#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // We declare variables for storing scores and weighting factors
    double grade1, weight1, grade2, weight2, grade3, weight3;

    grade1 = 90;
    grade2 = 80;
    grade3 = 78;
    weight1 = 0.30;
    weight2 = 0.25;
    weight3 = 0.45;

    // Calculation of the average weighted value for each exam
    double average_grade1 = grade1 * weight1;
    double average_grade2 = grade2 * weight2;
    double average_grade3 = grade3 * weight3;

    // Output of results for each exam
    cout << "First exam: assessment - " << grade1 << ", weighting factor - " << weight1 << ", weighted grade - " << average_grade1 << "\n";
    cout << "Second exam: evaluation - " << grade2 << ", weighting factor - " << weight2 << ", weighted grade - " << average_grade2 << "    \n";
    cout << "Third exam: assessment - " << grade3 << ", weighting factor - " << weight3 << ", weighted grade - " << average_grade3 << "\n";

    cout << fixed << setprecision(2); // The output is accurate to two decimal places

    // Derivation of the weighted average value for all grades
    double total_average_grade = (average_grade1 + average_grade2 + average_grade3) / (weight1 + weight2 + weight3);
    cout << "Weighted average value of all grades: " << total_average_grade << "\n";

    return 0;
}
