#include <iostream>
using namespace std;

// Custom data type for exam scores
typedef int ExamScore;

// Function to calculate the average of exam scores
float calculateAverage(ExamScore scores[]) {
    float sum = 0;
    for (int i = 0; i < 4; i++) {
        if (scores[i] < 0) {
            // Handle negative scores as an error
            return -1.0;
        }
        sum += scores[i];
    }
    return sum / 4;
}

int main() {
    long studentID;
    ExamScore scores[4];

    // Input student ID and exam scores
    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter four exam scores: ";
    for (int i = 0; i < 4; i++) {
        cin >> scores[i];
    }

    // Calculate the average
    float average = calculateAverage(scores);

    if (average < 0) {
        cout << "Error: Negative exam score entered." << endl;
    }
    else if (average >= 3) {
        cout << "Student ID: " << studentID << endl;
        cout << "Average Score: " << average << endl;

        if (average == 5) {
            cout << "Result: Excellent" << endl;
        }
        else if (average >= 4) {
            cout << "Result: Good" << endl;
        }
        else {
            cout << "Result: Satisfactory" << endl;
        }
    }
    else {
        cout << "Student ID: " << studentID << endl;
        cout << "Average Score: " << average << endl;
        cout << "Result: Exam not passed" << endl;
    }

    return 0;
}
