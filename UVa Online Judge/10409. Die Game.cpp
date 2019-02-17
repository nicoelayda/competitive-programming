#include <iostream>

using namespace std;

int top, north, west, south, east, bot;

void reset() {
    top = 1; bot = 6;
    north = 2; south = 5;
    west = 3; east = 4;
}

void cycle(int &n1, int &n2, int &n3, int &n4) {
    int temp = n1;
    n1 = n2;
    n2 = n3;
    n3 = n4;
    n4 = temp;
}

int main() {
    int c;
    string command;

    while (cin >> c && c != 0) {
        reset();
        while (c-- > 0) {
            cin >> command;

            if (command == "north")
                cycle(north, top, south, bot);

            else if (command == "west")
                cycle(west, top, east, bot);

            else if (command == "south")
                cycle(bot, south, top, north);
            
            else if (command == "east")
                cycle(bot, east, top, west);
        }

        cout << top << endl;
    }

    return 0;
}