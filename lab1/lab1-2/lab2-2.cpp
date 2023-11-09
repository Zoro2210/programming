#include <iostream>
#include <Windows.h>
using namespace std;

int main() {

    float museum = 1.5;
    float artgallery = 2.3;
    float bookstore = 5.9;
    float concert = 4;

    cout << "Distance to the museum " << museum / 4 << " km" << endl;
    cout << "Distance between the museum and the art gallery: " << artgallery / 4 << " km" << endl;
    cout << "Distance between the art gallery and the bookstore: " << bookstore / 4 << " km" << endl;
    cout << "Distance between the bookstore and the concert: " << concert / 4 << " km" << endl;

    float way = (museum + artgallery + bookstore + concert) / 4;
    float the_path_is_rounded = float(int(way * 10.0 + 0.5)) / 10.0;
    cout << "Complete path to follow: " << the_path_is_rounded << " km" << endl;

    return 0;
}