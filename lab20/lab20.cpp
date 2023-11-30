#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int numCandidates = 5;
const int numSettlements = 6;

// Function to generate the number of votes for candidates in each settlement
void generateVotes(int votes[numSettlements][numCandidates]) {
    for (int i = 0; i < numSettlements; ++i) {
        for (int j = 0; j < numCandidates; ++j) {
            votes[i][j] = rand() % 500 + 50 * (j + 1);
        }
    }
}

// Function to print the results table of the voting
void printResultsTable(int votes[numSettlements][numCandidates]) {
    cout << "Results Table:\n";
    cout << "Settlement\t";
    for (int j = 1; j <= numCandidates; ++j) {
        cout << "Candidate " << j << "\t";
    }
    cout << endl;

    for (int i = 0; i < numSettlements; ++i) {
        cout << i + 1 << "\t\t";
        for (int j = 0; j < numCandidates; ++j) {
            cout << votes[i][j] << "\t\t";
        }
        cout << endl;
    }
}

// Function to calculate the number of voters in each settlement
void calculateVoters(int votes[numSettlements][numCandidates], int voters[numSettlements]) {
    for (int i = 0; i < numSettlements; ++i) {
        int totalVotes = 0;
        for (int j = 0; j < numCandidates; ++j) {
            totalVotes += votes[i][j];
        }
        voters[i] = totalVotes;
    }
}

int main() {
    srand(time(NULL));

    int votes[numSettlements][numCandidates];
    int voters[numSettlements];

    // Generate votes
    generateVotes(votes);

    // Print the results table
    printResultsTable(votes);

    // Calculate the number of voters in each settlement
    calculateVoters(votes, voters);

    // Print the number of voters in each settlement
    cout << "\nNumber of voters in each settlement:\n";
    for (int i = 0; i < numSettlements; ++i) {
        cout << "Settlement " << i + 1 << ": " << voters[i] << " voters\n";
    }

    return 0;
}
