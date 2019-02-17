#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m && (n != 0 || m != 0)) {
        unsigned long long c = 1;
        bool divided[m+1];
        memset(divided, false, sizeof(bool) * (m+1));

        for (int i = m, j = n; i >= 1; i--, j--) {
            c *= j;

            bool all_divided = false;
            while (!all_divided) {
                all_divided = true;
                for (int i = 1; i <= m; i++) {
                    if (!divided[i] && c % i == 0) {
                        divided[i] = true;
                        all_divided = false;
                        c /= i;
                    }
                }
            }
        }

        cout << n << " things taken " << m << " at a time is " << c << " exactly." << endl;
    }
    return 0;
}