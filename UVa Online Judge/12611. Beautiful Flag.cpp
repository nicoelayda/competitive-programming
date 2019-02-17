#include <iostream>

using namespace std;

int main() {
    int T, r;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> r;

        cout << "Case " << t << ":" << endl;
        cout << ((int)(-2.25 * r)) << " " << ((int)(1.5 * r)) << endl;
        cout << ((int)(2.75 * r)) << " " << ((int)(1.5 * r)) << endl;
        cout << ((int)(2.75 * r)) << " " << ((int)(-1.5 * r)) << endl;
        cout << ((int)(-2.25 * r)) << " " << ((int)(-1.5 * r)) << endl;
    }
    return 0;
}