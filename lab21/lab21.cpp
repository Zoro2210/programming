#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// ������� ��� ��������� ������� � ����������� ������ ����������
void generateMatrix(int matrix[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 10; // ��� ��������, �������� �������� ����� �� 0 �� 9
        }
    }
}

// ������� ��� ��������� ������� � ����
void writeMatrixToFile(int matrix[][10], int size, const char* filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Unable to open " << filename << " for writing.\n";
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }

    outFile.close();
}

// ������� ��� ���������� ������� � �����
void readMatrixFromFile(int matrix[][10], int size, const char* filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open " << filename << " for reading.\n";
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(inFile >> matrix[i][j])) {
                cerr << "Error reading from file " << filename << ".\n";
                exit(1);
            }
        }
    }

    inFile.close();
}

// ������� ��� ���������� ������� C
void calculateMatrixC(int A[][10], int B[][10], int C[][10], int size) {
    int B_squared[10][10];

    // ��������� B^2
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            B_squared[i][j] = pow(B[i][j], 2);
        }
    }

    // ��������� C = 3(A^T - B^2)B
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = 3 * (A[j][i] - B_squared[i][j]) * B[i][j];
        }
    }
}

int main() {
    int i = 6; // ��� ����� �������
    int n = i + 4;
    int A[10][10], B[10][10], C[10][10];

    // ����������� ������� A � B
    generateMatrix(A, n);
    generateMatrix(B, n);

    // �������� ������� A � B � ����� a.txt � b.txt ��������
    writeMatrixToFile(A, n, "a.txt");
    writeMatrixToFile(B, n, "b.txt");

    // ��������� ������� C
    calculateMatrixC(A, B, C, n);

    // �������� ������� C � ���� c.txt
    writeMatrixToFile(C, n, "c.txt");

    return 0;
}
