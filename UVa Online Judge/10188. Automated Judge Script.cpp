#include <iostream>

using namespace std;

int main() {
    int n, m, tc = 0;

    while (cin >> n && n != 0) {
        cin.ignore();

        string output = "";
        string judge = "";

        string numeric_output = "";
        string numeric_judge = "";

        string line;
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            output += line + "\n";
        }

        cin >> m;
        cin.ignore();
        for (int i = 0; i < m; i++) {
            getline(cin, line);
            judge += line + "\n";
        }

        if (output == judge) {
            cout << "Run #" << ++tc << ": Accepted" << endl;
            continue;
        }

        for (int i = 0; i < output.length(); i++) {
            if (output[i] >= '0' && output[i] <= '9') {
                numeric_output += output[i];
            }
        }

        for (int i = 0; i < judge.length(); i++) {
            if (judge[i] >= '0' && judge[i] <= '9') {
                numeric_judge += judge[i];
            }
        }

        if (numeric_output == numeric_judge) {
            cout << "Run #" << ++tc << ": Presentation Error" << endl;
        }
        else {
            cout << "Run #" << ++tc << ": Wrong Answer" << endl;
        }
    }

    return 0;
}