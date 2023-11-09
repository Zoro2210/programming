#include<iostream>

using namespace std;

int PrintFactorial(int n) {
	if (n == 0) {
		return 1;
	}

	return n * (n - 1);
}

int main() {
	int n;
	cout << "Specify pure to calculate the factorial: ";
	cin >> n;
	int PF = PrintFactorial(n);
	cout << "Your numer " << n << " is equal to factorial "  << PF << endl;

}