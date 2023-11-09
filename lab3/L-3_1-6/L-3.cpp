#include <iostream>
#include<Windows.h>

using namespace std;

int main() {

    const int secondsPerMinute = 60;
    const int minutesPerHour = 60;
    const int hoursPerDay = 24;
    const int daysPerWeek = 7;
    const int daysPerYear = 365;
    const int secondsPerDay = secondsPerMinute * minutesPerHour * hoursPerDay;
    const int secondsPerWeek = secondsPerDay * daysPerWeek;
    const int secondsPerYear = secondsPerDay * daysPerYear;

    cout << "Seconds per day: " << secondsPerDay << std::endl;
    cout << "Seconds per week: " << secondsPerWeek << std::endl;
    cout << "Seconds per year: " << secondsPerYear << std::endl;

    return 0;
}
