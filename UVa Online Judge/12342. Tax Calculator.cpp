#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        int k;
        cin >> k;

        int tax = 0;

        // first 180k
        k -= 180000;

        // next 300k
        if (k > 0) {
            tax += ceil(min(300000, k) * 0.1);
            k -= 300000;
        }

        // next 400k
        if (k > 0) {
            tax += ceil(min(400000, k) * 0.15);
            k -= 400000;
        }

        // next 300k
        if (k > 0) {
            tax += ceil(min(300000, k) * 0.2);
            k -= 300000;
        }

        // the rest
        if (k > 0) {
            tax += ceil(k * 0.25);
        }

        if (tax != 0)
            cout << "Case " << tc << ": " << max(tax, 2000) << endl;
        else
            cout << "Case " << tc << ": " << 0 << endl;
    }
    return 0;
}