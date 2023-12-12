#include <iostream>
#include <cmath>
using namespace std;
int main() {
	// Задані координати центру кола та його радіус
	double centerX, centerY, radius;
	cout << "Enter the coordinates of the center of the circle (x, y): ";
	cin >> centerX >> centerY;
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	// Введення координат точки
	double x, y;
	cout << "Enter the coordinates of the point (x, y): ";
	cin >> x >> y;
	// Розрахунок відстані від точки до центру кола
	double distance = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y -
		centerY));
	// Перевірка, чи точка лежить в середені кола
	if (distance <= radius) {
		cout << "The point lies inside the circle" << endl;
	}
	else {
		cout << "The point is outside the circle" << endl;
		cout << "Do you want to enter the coordinates of an existing point (1 - Yes, 0 - No): ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			// Введення нових координат точки
			cout << "Enter the coordinates of the new point (x, y): ";
			cin >> x >> y;
			distance = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y -
				centerY));
			if (distance <= radius) {
				cout << "The new point lies inside the circle" << endl;
			}
			else {
				cout << "The new point lies outside the circle" << endl;
			}
		}
	}
	return 0;
}