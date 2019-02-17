#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;

    while (cin >> n >> k) {
        k = min(k, n - k);
        
        double digits = 0;
        for (int i = 1; i <= k; i++) {
            digits += log10(1.0 * (n - k + i) / i);
        }

        cout << (floor(digits) + 1) << endl;
    }
}