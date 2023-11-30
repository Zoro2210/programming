#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Declaration of file streams
    ifstream infile;
    ofstream outfile;

    // Opening the file for reading
    infile.open("input_data.dat");

    // Check if the file was successfully opened
    if (!infile) {
        cerr << "Failed to open the file input_data.dat" << endl;
        return 1; // Error opening the file
    }

    // Reading numbers from the file and calculating the average
    double sum = 0.0;
    double num;
    int count = 0;

    while (infile >> num) {
        sum += num;
        count++;
    }

    infile.close(); // Closing the file after reading

    // Calculating the average
    double average = (count > 0) ? (sum / count) : 0.0;

    // Opening the file for writing the results
    if (average > 0) {
        outfile.open("plus.rez");
    }
    else {
        outfile.open("minus.rez");
    }

    // Check if the output file was successfully opened
    if (!outfile) {
        cerr << "Failed to open the output file" << endl;
        return 2; // Error opening the output file
    }

    // Writing the results to the file
    outfile << "Average: " << average << endl;

    outfile.close(); // Closing the file after writing

    cout << "Results have been successfully written to the file." << endl;

    return 0;
}
