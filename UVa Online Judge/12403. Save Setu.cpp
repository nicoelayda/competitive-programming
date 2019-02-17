#include <iostream>

using namespace std;

int main() {
    int T, transaction, balance = 0;
    cin >> T;

    while (T-- != 0) {
        string cmd;
        cin >> cmd;

        if (cmd == "donate") {
            cin >> transaction;
            balance += transaction;
        }
        else if (cmd == "report") {
            cout << balance << endl;
        }
    }
}