#include<iostream>

using namespace std;

void PrintTemp(double celsius) {
	double FF = 1.8 * celsius + 32.0;//Formule of Ferenheit
	cout << celsius << " degrees Celsius is equal to " << FF << " degrees Fahrenheit" << endl;
}

int main() {
	double celsius;
	cout << "Please enter the temperature in degrees Celsius: ";
	cin >> celsius;
	PrintTemp(celsius);

	return 0;

}