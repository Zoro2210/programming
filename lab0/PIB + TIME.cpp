#include <iostream>
#include <ctime>
#include<string>

using namespace std;

int main() {

    // Name
    cout << "Hulka Dima" << endl;

    // Getting current time
    time_t currentTime;
    time(&currentTime);

    // Convet to local time
    tm localTime;
    if (localtime_s(&localTime, &currentTime) == 0) {
        cout << "Curent time: ";
        cout << localTime.tm_hour << ":" << localTime.tm_min << ":" << localTime.tm_sec << endl;
    }

    return 0;
}
