#include <iostream>
#include <sstream>

using namespace std;

int str_to_int(string str) {
    int n;
    stringstream ss(str);
    ss >> n;
    return n;
}

int main() {
    int T;
    cin >> T;

    while (T-- != 0) {
        int n, p = 0;
        string cmd;

        cin >> n;
        cin.ignore();

        int move[n];

        for (int i = 0; i < n; i++) {
            getline(cin, cmd);

            if (cmd == "LEFT") {
                move[i] = -1;
            }
            else if (cmd == "RIGHT") {
                move[i] = 1;
            }
            else {
                move[i] = move[str_to_int(cmd.substr(8)) - 1];
            }
                p += move[i];
        }

        cout << p << endl;
    }

    return 0;
}