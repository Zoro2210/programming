#include <iostream>
#include <string>

using namespace std;

double PrintGarm(const double x, const double y) {

    if (x == 0 || y == 0) {
        return 0;
    }

    double formulaGarm = (2.0 * x * y) / (x + y);
    return formulaGarm;

}

int main() {

    double x, y;

    bool terminate_while = false;
    string request_type;

    do {

        cout << "Hello, selection (y/n): ";
        cin >> request_type;
        if (request_type != "n") {

            cout << "Hello, enter please first and second number: ";
            cin >> x >> y;

            double resultGarm = PrintGarm(x, y);

            if (resultGarm == 0) {
                cout << "Invalid garm" << endl;
            }
            else {
                cout << "Garm: " << resultGarm << endl;
            }
        }
        else if (request_type == "n") {
            terminate_while = true;
            cout << "OK" << endl;
        }

    }

    while (!terminate_while);


    return 0;
}
