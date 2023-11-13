```
#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n == 0  n == 1) {  // Fixed the condition here
        return 1;
    }
    else {
        unsigned long long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}

int main() {
    int n;
    char choice;

    do {
        cout << "Enter an integer to calculate its factorial: ";
        cin >> n;

        if (n < 0) {
            cout << "Factorial is defined only for non-negative integers." << endl;
        }
        else {
            cout << n << "! = " << factorial(n) << endl;
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y'  choice == 'Y');  // Fixed the condition here

    return 0;
}
```