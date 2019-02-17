#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int x;
        cin >> x;

        for (int m, i = 1; i < n; i++) {
            cin >> m;
            x ^= m;
        }

        cout << (x != 0 ? "Yes" : "No") << endl;
    }
    return 0;
}