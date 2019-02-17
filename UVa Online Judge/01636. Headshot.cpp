#include <iostream>

using namespace std;

int main() {
    string rounds;

    while (cin >> rounds) {
        int empty = 0, safe = 0;

        for (int i = 0; i < rounds.length(); i++) {
            if (rounds[i] == '0') {
                empty++;
                if (rounds[(i + 1) % rounds.length()] == '0')
                    safe++;
            }
        }

        double rotate = 1.0 * empty / rounds.length();
        double shoot = 1.0 * safe / empty;

        if (shoot == rotate)
            cout << "EQUAL" << endl;
        else if (shoot > rotate)
            cout << "SHOOT" << endl;
        else
            cout << "ROTATE" << endl;
    }
    return 0;
}