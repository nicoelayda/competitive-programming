#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string line;
    int n, i, j, tc = 0;

    while (cin >> line) {
        cin >> n;
        cout << "Case " << ++tc << ":" << endl;

        while (n-- != 0) {
            cin >> i >> j;

            int lb = min(i, j);
            int ub = max(i, j);

            char ch = line[lb];
            bool same = true;
            
            for (int a = lb; a <= ub; a++) {
                if (line[a] != ch) {
                    same = false;
                    break;
                }
            }

            cout << (same ? "Yes" : "No") << endl;
        }
    }

    return 0;
}