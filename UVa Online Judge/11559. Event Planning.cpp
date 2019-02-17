#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, b, h, w;

    while (cin >> n >> b >> h >> w) {
        int min_cost = INT_MAX;

        while (h-- > 0) {
            int p, a;
            cin >> p;
            for (int wk = 0; wk < w; wk++) {
                cin >> a;
                if (a >= n && p * n <= b) {
                    min_cost = min(min_cost, p * n);
                }
            }
        }

        if (min_cost == INT_MAX)
            cout << "stay home" << endl;
        else
            cout << min_cost << endl;

    }
    return 0;
}