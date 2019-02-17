#include <iostream>

using namespace std;

int main() {
    int n, tc = 0;

    while (cin >> n && n != 0) {
        int event, balance = 0;

        while (n-- != 0) {
            cin >> event;
            balance += event == 0 ? -1 : 1;
        }
        cout << "Case " << ++tc << ": " << balance << endl;
    }

    return 0;
}