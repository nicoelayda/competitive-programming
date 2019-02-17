#include <iostream>

using namespace std;

int main() {
    string s, t;

    while (cin >> s >> t) {
        int matches = 0;
        for (int ti = 0; ti < t.length() && matches != s.length(); ti++) {
            if (s[matches] == t[ti]) {
                matches++;
            }
        }

        cout << (matches == s.length() ? "Yes" : "No") << endl;
    }

    return 0;
}