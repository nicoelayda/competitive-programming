#include <iostream>
#include <cmath>

using namespace std;

const double rad = M_PI / 180;

int main() {
    int T;
    cin >> T;
 
    while (T-- != 0) {
        int num_commands;
        double x = 0, y = 0, angle = 0;

        cin >> num_commands;
 
        while (num_commands-- != 0) {
            string command;
            double magnitude;
 
            cin >> command >> magnitude;
 
            if (command == "fd") {
                x += cos(angle * rad) * magnitude;
                y += sin(angle * rad) * magnitude;
            }
            else if (command == "bk") {
                x -= cos(angle * rad) * magnitude;
                y -= sin(angle * rad) * magnitude;
            }
            else if (command == "lt") {
                angle -= magnitude;
            }
            else if (command == "rt") {
                angle += magnitude;
            }
        }
 
        cout << int(round(sqrt(x*x + y*y))) << endl;
    }
 
    return 0;
}